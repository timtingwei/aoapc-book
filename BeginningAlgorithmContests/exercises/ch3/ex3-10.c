// copyright [2018] <mituh>
// UVa1587 - Box

#include <stdio.h>
#include <string.h>
#define MAXN 10000 + 10

int find_int(const int *a, const int i, const int n) {
  // 在大小为n的整数数组a中找i
  for (int j = 0; j < n; j++) {
    if (a[j] == i) return 1;
  }
  return 0;
}

int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("b.out", "w", stdout);
#endif
  int a[6][2] = {};
  int a0, a1, b0, b1, c0, c1, d0, d1, e0, e1, f0, f1;
  while (scanf("%d %d %d %d %d %d  %d %d %d %d %d %d",
               &a0, &a1, &b0, &b1, &c0, &c1,
               &d0, &d1, &e0, &e1, &f0, &f1) == 12) {
    /*
      for (int i = 0; i < 6; i++) {
      scanf("%d %d", &a[i][0], &a[i][1]);
      // printf("%d %d\n", a[i][0], a[i][1]);
      }
    */
    memset(a, 0, sizeof(a));
    int a[6][2] = {{a0, a1}, {b0, b1}, {c0, c1}, {d0, d1}, {e0, e1}, {f0, f1}};

    int a_use[6] = {}, cnt = 0;
    for (int i = 0; i < 6; i++) {
      for (int j = 0; j < 6; j++) {
        if ((j == i) || (find_int(a_use, j, cnt) || find_int(a_use, i, cnt)))
          continue;
        if ((a[i][0] == a[j][0] && a[i][1] == a[j][1]) ||
            (a[i][1] == a[j][0] && a[i][0] == a[j][1])) {
          a_use[cnt++] = i;
          a_use[cnt++] = j;
          break;
        }
      }
    }
    /*
      for (int i = 0; i < cnt; i++) {
      printf("a_use[%d] = %d\n", i, a_use[i]);
      }
    */
    (cnt == 6) ? printf("POSSIBLE\n") : printf("IMPOSSIBLE\n");
  }
  return 0;
}


/*
1 2
2 1
3 1
2 2
1 2
3 3

3 3
3 2
3 2
2 2
3 3
2 2

*/
