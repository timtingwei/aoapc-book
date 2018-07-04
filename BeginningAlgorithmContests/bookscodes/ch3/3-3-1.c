// copyright [2018] <mituh>
// snake
// 自己的做法
// 根据每次在某一方向上移动的规律, 将所有移动行为放入一维数组a_drc
// n = 6
// 2 30 12 30 12 30
// 5 55 44 33 22 11
// 2 30 12 30 12 30

#include <stdio.h>
#include <time.h>
#define MAXN 10000000
int a[MAXN];
int a_drc[MAXN];

int main() {
  int n;
  scanf("%d", &n);
  int drc = 2, drc_cnt = n -1, cnt = 0;
  for (int i = 0; i < 2*n-1; i++) {
    for (int j = 0; j < drc_cnt; j++) {
      a_drc[cnt++] = drc;
    }
    if ((i != 0) && (i % 2 == 0)) drc_cnt--;
    drc = (++drc == 4) ? 0 : drc;
  }

  int x = 1, y = n;
  a[y] = 1;
  for (int i = 0; i < cnt; i++) {
    if (a_drc[i] == 0) x--;  // 0 : x--;
    if (a_drc[i] == 1) y++;  // 1 : y++;
    if (a_drc[i] == 2) x++;  // 2 : x++;
    if (a_drc[i] == 3) y--;  // 3 : y--;
    a[(x-1)*n + y] = i+2;
    // printf("%d %d\n", (x-1)*n + y, i+2);
  }

  cnt = 0;
  int first = 1;
  for (int i = 1; i <= n*n; i++) {
    if (first) first = 0; else printf(" "); printf("%d", a[i]);
    if (++cnt == n) {cnt = 0; first = 1; printf("\n");}
  }

  printf("Use time: %f\n", (double)clock()/CLOCKS_PER_SEC);
  return 0;
}

// echo 80 | ./3-3-1.out
// Use time: 0.005970

// echo 800 | ./3-3-1.out
// Use time: 0.236074
