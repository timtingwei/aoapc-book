// copyright [2018] <mituh>
// snake
// 书中例子, 二维数组, 使用while不确定循环次数
// 向某一方向不超过边界, 且不能占据已经占据的空间

#include <stdio.h>
#include <string.h>
#include <time.h>
#define MAXN 10000
#define MAXM 10000
int a[MAXM][MAXN];

int main() {

  int n, x, y, tot = 0;
  scanf("%d", &n);
  memset(a, 0, sizeof(a));

  tot = a[x = 0][y = n-1] = 1;
  while (tot < n * n) {
    while (x + 1 <  n && !a[x+1][y]) a[++x][y] = ++tot;
    while (y - 1 >= 0 && !a[x][y-1]) a[x][--y] = ++tot;
    while (x - 1 >= 0 && !a[x-1][y]) a[--x][y] = ++tot;
    while (y + 1 <  n && !a[x][y+1]) a[x][++y] = ++tot;
  }

  int first = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (first) first = 0; else printf(" "); printf("%d", a[i][j]);
    }
    printf("\n");
    first = 1;
  }

  printf("Use time: %f\n", (double)clock()/CLOCKS_PER_SEC);
  return 0;
}

// echo 80 | ./3-3.out
// Use time: 0.232251

// echo 800 | ./3-3.out
// Use time: 0.459426
