// copyright [2018] <mituh>
// UVa1587 - Box(盒子)
/*
  思路: 3面两两匹配 --> 面0 面1 边存在交集 --> 面2 与 (面0 u 面1)-(面0 n 面1）匹配
 */

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

    int a_use[6] = {}, cnt = 0, b_use[3][2] = {}, b_cnt = 0;
    for (int i = 0; i < 6; i++) {
      for (int j = 0; j < 6; j++) {
        if ((j == i) || (find_int(a_use, j, cnt) || find_int(a_use, i, cnt)))
          continue;
        if ((a[i][0] == a[j][0] && a[i][1] == a[j][1]) ||
            (a[i][1] == a[j][0] && a[i][0] == a[j][1])) {
          a_use[cnt++] = i;
          a_use[cnt++] = j;
          memcpy(b_use[b_cnt++] , a[i], sizeof(a[i]));
          break;
        }
      }
    }
    /*
      for (int i = 0; i < cnt; i++) {
        printf("a_use[%d] = %d\n", i, a_use[i]);
      }
    */
    if (cnt != 6) {
      // 3面不匹配
      printf("IMPOSSIBLE\n");
    } else {
      // 3面两两匹配
      // int match = 0, ma = 0, mb = 0;
      /*
      if (b_use[0][0] == b_use[1][0]) {match = 1; ma = 1, mb = 1;
      } else if (b_use[0][0] == b_use[1][1]) {match = 1; ma = 1, mb = 0;
      } else if (b_use[0][1] == b_use[1][0]) {match = 1; ma = 0, mb = 1;
      } else if (b_use[0][1] == b_use[1][1]) {match = 1; ma = 0, mb = 0;}
      */
      int find = 0;
      for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
          int match = 0, ma = 0, mb = 0;
          if (b_use[0][i] == b_use[1][j]) {match = 1; ma = !i, mb = !j;}
          if (match) {
            // 一旦此时面0, 面1存在交
            if (((b_use[2][0] == b_use[0][ma]) &&
                 (b_use[2][1] == b_use[1][mb]))
                ||
                ((b_use[2][0] == b_use[1][mb]) &&
                 (b_use[2][1] == b_use[0][ma]))) {
              // 面2 与 (面0 u 面1)-(面0 n 面1）匹配
              find = 1;
              printf("POSSIBLE\n");
              break;
            }
          }
        }
        if (find) break;
      }
      if (!find) printf("IMPOSSIBLE\n");
    }
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

3 2
3 2
2 3
3 2
3 3
3 3
*/
