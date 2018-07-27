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
#include <cstring>
#include <iostream>
#include <vector>
using std::cin; using std::cout;
using std::vector; using std::string;
const int MAXN = 10000;
vector<int> piles[MAXN];
int N;
// int pos[MAXN][MAXN];  // 储存每个木块当前的pile, height
// 只作为一个想法, 仍旧用搜索的方法, 找到木块的pile, height

void addpile(int n) {
  for (int i = 0; i < n; i++) { vector<int> ivec = {i}; piles[i] = ivec;}
}

void printpile() {
  for (int i = 0; i < N; i++) {
    cout << i << ":";
    for (int j = 0; j < piles[i].size(); j++) {
      cout << " " << piles[i][j];
    }
    cout << "\n";
  }
  cout << "\n";
}

// 找到编号为ib的木块, 在p堆, 高度h
void findblock(int ib, int* p, int* h) {
  // pos[0] -> wpile, pos[1] -> wpos
  // if (ib >= N) {cout << "findblock error:ib>=n\n"; return;}
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < piles[i].size(); j++) {
      if (piles[i][j] == ib) { *p = i; *h = j; return;}
    }
  }
}

// 归位 p堆高度h以上的木块
void clear_above(int p, int h) {
  // 将wp(pile索引), wh(高度索引)以上全部归位, 目前pile的高度是size 0 1 2 => 3
// printf("a: size=%d, wp=%d, wh=%d\n", size, wp, wh);
  for (int i = h + 1; i < piles[p].size(); i++) {
    int b = piles[p][i];
    piles[b].push_back(b);     // 归位
  }
  piles[p].resize(h+1);        // 只留下下标0～h
// cout << "init above " << wp << " " << wh << "\n";
}

// 将p堆高度h以上的木块, 整体移动到p2堆的上部
void pile_onto(int p, int h, int p2) {
  for (int i = h; i < piles[p].size(); i++) {
    piles[p2].push_back(piles[p][i]);
  }
  piles[p].resize(h);
}

/*
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

// cout << "move " << a << " onto " << b << "\n";
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
// cout << "move " << a << " over " << b << "\n";
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
// cout << "pile " << a << " over " << b << "\n";
}

void pile_onto(int a, int b) {
  // 1, 把b上方的木块全部归位, 2, 然后把a及上面的木块整体摞在b上
  if (a == b) return;   // 非法指令, a和b在同一堆
  findblock(b, N, blk_pos);
  int size = piles[blk_pos[0]].size(), wp = blk_pos[0], wh = blk_pos[1];
  initblocks(size, wp, wh);

  // 2, 然后把a及上面的木块整体摞在b上
  pile_over(a, b);

// cout << "pile " << a << " onto " << b << "\n";
}
*/

int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("b.out", "w", stdout);
#endif
  if (scanf("%d", &N) == 1 && N) {
    int a, b;
    string s1, s2;
    addpile(N);
    while (cin >> s1 >> a >> s2 >> b) {
      int pa, pb, ha, hb;
      findblock(a, &pa, &ha);
      findblock(a, &pb, &hb);
      if (pa == pb) {continue;}       // 排序
      if (s2 == "onto") clear_above(pb, hb);
      if (s1 == "move") clear_above(pa, ha);
      pile_onto(pa, ha, pb);
    }
    printpile();
    /*
      for (;;) {
      string s1, s2;
      int a, b;
      cin >> s1;
      if (s1 == "quit") break;
      cin >> a >> s2 >> b;
      if (s1[0] == 'm') {
      if (s2[1] == 'n') move_onto(a, b);
      else if (s2[1] == 'v') move_over(a, b);
      } else if (s1[0] == 'p') {
      if (s2[1] == 'n') pile_onto(a, b);
      else if (s2[1] == 'v') pile_over(a, b);
      }
      }
      printpile(N);
      }
    */
  }

  return 0;
}

/*
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
