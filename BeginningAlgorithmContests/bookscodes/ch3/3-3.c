// copyright [2018] <mituh>
// snake

#include <stdio.h>
#include <string.h>
#include <time.h>
#define MAXN 100000
#define MAXM 100000
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
