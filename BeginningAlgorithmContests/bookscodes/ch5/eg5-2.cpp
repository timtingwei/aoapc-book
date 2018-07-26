// copyright [2018] <mituh>
// UVa 101, the Blocks Problem
/*
  思路: 木块堆长度不一定, 用vector存储每个编号对应的木块, 用vector<int> a[]放所有编号

10
move 9 onto 1
move 8 over 1
move 7 over 1
move 6 over 1
pile 8 over 6
pile 8 over 5
move 2 over 1
move 4 over 9
quit

0: 0
1: 1 9 2 4
2:
3: 3
4:
5: 5 8 7 6
6:
7:
8:
 9:
 */

#include <cstdio>
#include <iostream>
#include <vector>
using std::cin; using std::cout;
using std::vector;
const int MAXN = 10000;
vector<int> piles[MAXN];
int N = 10;
// int pos[MAXN][MAXN];  // 储存每个木块当前的pile, height
// 只作为一个想法, 仍旧用搜索的方法, 找到木块的pile, height

void addpile(int n) {
  for (int i = 0; i < n; i++) { vector<int> ivec = {i}; piles[i] = ivec;}
}

int blk_pos[3];  // 用于find时, 保存木块的位置
void findblock(int ib, int n, int* pos) {
  // pos[0] -> wpile, pos[1] -> wpos
  memset(blk_pos, 0, sizeof(blk_pos));
  if (ib >= n) {cout << "findblock:ib>=n\n"; return;}
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < piles[i].size(); j++) {
      if (piles[i][j] == ib) { pos[0] = i; pos[1] = j; return;}
    }
  }
}

void initblocks(int size, int wp, int wh) {
  // 将wp(pile索引), wh(高度索引)以上全部归位, 目前pile的高度是size 0 1 2 => 3
// printf("a: size=%d, wp=%d, wh=%d\n", size, wp, wh);
  for (int i = size - 1; i > wh; i--) {
    piles[piles[wp][i]] = {piles[wp][i]};        // 归位
    piles[wp].pop_back();                        // 从当前pile, pop_back()
  }
  cout << "init above " << wp << " " << wh << "\n";
}

void move_onto(int a, int b) {
  // 把a和b上方的木块全部归位, 然后把a摞在b上面
  if (a == b) return;   // 非法指令, a和b在同一堆
  // 找到a在哪个pile(wp)的哪个位置(wh)
  findblock(a, N, blk_pos);
  // 将a以上木块, 在当前位置pop, 归初始位
  int size = piles[blk_pos[0]].size(), wp = blk_pos[0], wh = blk_pos[1];
  initblocks(size, wp, wh);
  // 将a也从当前位置pop
  piles[wp].pop_back();

  // 找到b在哪个pile(wp)的哪个位置(wh)
  findblock(b, N, blk_pos);
  // 将b以上木块, 从当前堆pop, 归初始位
  size = piles[blk_pos[0]].size(); wp = blk_pos[0]; wh = blk_pos[1];
  initblocks(size, wp, wh);
  // 把a push_back进b pile
  piles[wp].push_back(a);

  cout << "move " << a << " onto " << b << "\n";
}

void move_over(int a, int b) {
  // 把a上方的木块全部归位, 然后把a放在b所在木块堆的顶部
  if (a == b) return;   // 非法指令, a和b在同一堆
  findblock(a, N, blk_pos);
  int size = piles[blk_pos[0]].size(), wp = blk_pos[0], wh = blk_pos[1];
  initblocks(size, wp, wh);
  // 将a也从当前位置pop
  piles[wp].pop_back();

  findblock(b, N, blk_pos);
  piles[blk_pos[0]].push_back(a);
  cout << "move " << a << " over " << b << "\n";
}

void pile_over(int a, int b) {
  // 把a及上面的木块整体摞在b所在的木块堆的顶部
  if (a == b) return;   // 非法指令, a和b在同一堆
  findblock(b, N, blk_pos);
  int wp_b = blk_pos[0];
  findblock(a, N, blk_pos);
  int size = piles[blk_pos[0]].size(), wp = blk_pos[0], wh = blk_pos[1];
  // 将a及以上整体push_back到b的顶部
  for (int i = wh; i < size; i++) {
    piles[wp_b].push_back(piles[wp][i]);     // 边添加
    piles[wp].pop_back();                    // 边删除
  }
}

void pile_onto(int a, int b) {
  // 1, 把b上方的木块全部归位, 2, 然后把a及上面的木块整体摞在b上
  if (a == b) return;   // 非法指令, a和b在同一堆
  findblock(b, N, blk_pos);
  int size = piles[blk_pos[0]].size(), wp = blk_pos[0], wh = blk_pos[1];
  initblocks(size, wp, wh);

  // 2, 然后把a及上面的木块整体摞在b上
  pile_over(a, b);
  /*
  int wp_b = wp;
  findblock(a, N, blk_pos);
  size = piles[blk_pos[0]].size(); wp = blk_pos[0]; wh = blk_pos[1];
  // 将a push_back()到归位后的b以上
  for (int i = wh; i < size; i++) {
    piles[wp_b].push_back(piles[wp][i]);     // 边添加
    piles[wp].pop_back();                    // 边删除
  }
  */
  cout << "pile " << a << " onto " << b << "\n";
}

void printpile(const int &n) {
  for (int i = 0; i < n; i++) {
    cout << i << ":";
    for (int j = 0; j < piles[i].size(); j++) {
      cout << " " << piles[i][j];
    }
    cout << "\n";
  }
}

int main() {
  addpile(N);
  printpile(N);

  /*
  move_over(0, 8);
  move_over(4, 8);
  move_over(5, 8);
  printpile(N);
  move_over(4, 1);
  printpile(N);
  pile_onto(8, 1);
  printpile(N);
  */



  move_onto(9, 1);
  printpile(N);
  move_over(8, 1);
  printpile(N);
  move_over(7, 1);
  printpile(N);
  move_over(6, 1);
  printpile(N);
  pile_over(8, 6);
  printpile(N);
  pile_over(8, 5);
  printpile(N);
  move_over(2, 1);
  printpile(N);
  move_over(4, 9);
  printpile(N);


  return 0;
}

/*
move 9 onto 1
move 8 over 1
move 7 over 1
move 6 over 1
pile 8 over 6
pile 8 over 5
move 2 over 1
move 4 over 9
*/
