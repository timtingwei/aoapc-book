// copyright [2018] <mituh>
// UVa 101, the Blocks Problem
/*
  思路:
  木块堆长度不一定, 用vector存储每个编号对应的木块, 用vector<int> a[]放所有编号
  只作为一个想法, 仍旧用搜索的方法, 找到木块的pile, height
  对四种动作归类, 能先总结出共性, 总体操作就三个,
  1, findpile, 找到编号为ib的木块, 在p堆, 高度h
  2, clear_above, 归位 p堆高度h以上的木块
  3, pile_onto, 将p堆高度h以上的木块, 整体移动到p2堆的上部

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
const int MAXN = 30;
vector<int> piles[MAXN];
int N;

void printpile() {
  for (int i = 0; i < N; i++) {
    cout << i << ":";
    for (int j = 0; j < piles[i].size(); j++) {
      cout << " " << piles[i][j];
    }
    cout << "\n";
  }
}

// 找到编号为ib的木块, 在p堆, 高度h
void findblock(int ib, int* p, int* h) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < piles[i].size(); j++) {
      if (piles[i][j] == ib) { *p = i; *h = j; return;}
    }
  }
}
// 找到编号为ib的木块, 在p堆, 高度h
// 归位 p堆高度h以上的木块
void clear_above(int p, int h) {
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

int main() {
  if (scanf("%d", &N) == 1 && N) {
    int a, b;
    string s1, s2;
    for (int i = 0; i < N; i++) { vector<int> ivec = {i}; piles[i] = ivec;}
    while (cin >> s1) {
      if (s1 == "quit") break;
      cin >> a >> s2 >> b;
      int pa, pb, ha, hb;
      findblock(a, &pa, &ha);
      findblock(b, &pb, &hb);
      if (pa == pb) continue;   // 非法指令
      if (s2 == "onto") clear_above(pb, hb);
      if (s1 == "move") clear_above(pa, ha);
      pile_onto(pa, ha, pb);
    }
    printpile();
  }
  return 0;
}
