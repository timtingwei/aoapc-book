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
int N = 9;
// int pos[MAXN][MAXN];  // 储存每个木块当前的pile, height
// 只作为一个想法, 仍旧用搜索的方法, 找到木块的pile, height

void addpile(int n) {
  for (int i = 0; i < n; i++) { vector<int> ivec = {i}; piles[i] = ivec;}
}

int blk_pos[3];  // 用于find时, 保存木块的位置
void findblock(int ib, int n, int* pos) {
  // pos[0] -> wpile, pos[1] -> wpos
  if (ib >= n) {cout << "findblock:ib>=n\n"; return;}
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < piles[i].size(); j++) {
      if (piles[i][j] == ib) { pos[0] = i; pos[1] = j; return;}
    }
  }
}

void move_onto(int a, int b) {
  // 把a和b上方的木块全部归位, 然后把a摞在b上面
  // 找到a在哪个pile(wp)的哪个位置(wh)
  memset(blk_pos, 0, sizeof(blk_pos));
  findblock(a, N, blk_pos);
  // 将a, b以上木块, 在当前位置pop, 归初始位, // 改变各自的位置计数
  int size = piles[blk_pos[0]].size(), wp = blk_pos[0], wh = blk_pos[1];
  printf("a: size=%d, wp=%d, wh=%d\n", size, wp, wh);
  for (int i = size - 1; i > wh; i--) {
    piles[piles[wp][i]] = {piles[wp][i]};   // 归位
    piles[wp].pop_back();                        // 从当前pile, pop_back()
  }
  // 将a也从当前位置pop
  piles[wp].pop_back();

  // 找到a在哪个pile(wp)的哪个位置(wh)
  memset(blk_pos, 0, sizeof(blk_pos));
  findblock(b, N, blk_pos);
  // 将b以上木块, 从当前堆pop, 归初始位
  size = piles[blk_pos[0]].size(); wp = blk_pos[0]; wh = blk_pos[1];
  printf("b: size=%d, wp=%d, wh=%d\n", size, wp, wh);
  for (int i = size - 1; i > wh; i--) {
    piles[piles[wp][i]] = {piles[wp][i]};   // 归位
    piles[wp].pop_back();                        // 从当前pile, pop_back()
  }
  // 把apush_back进b pile
  piles[wp].push_back(a);
  cout << "move " << a << " onto " << b << "\n";
}
void move_over(int a, int b) {
  // 把a上方的木块全部归位, 然后把a放在b所在木块堆的顶部
}
void pile_onto(int a, int b) {
  // 把b上方的木块全部归位, 然后把a及上面的木块整体摞在b上
}
void pile_over(int a, int b) {
  // 把a及上面的木块整体摞在b所在的木块堆的内部
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
  move_onto(2, 1);
  printpile(N);
  return 0;
}
