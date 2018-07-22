// copyright [2018] <mituh>
// UVa 133, The Dole Queue(救济金发放)
#include <stdio.h>
#include <string.h>
#define MAXN 20 + 5
int a[MAXN];
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("b.out", "w", stdout);
#endif
  int kase = 0;
  int n, k, m;
  while (scanf("%d %d %d", &n, &k, &m) == 3 && n) {
    // if (++kase != 1) printf("\n");
    memset(a, 0, sizeof(a));
    for (int i = 1; i <= n; i++) a[i] = 0;
    int i = 1, j = n, ck = k, cm = m, cnt = 0;
    while (cnt < n) {     // or cnt != n
      k = ck, m = cm;
      for (;;) {
        if (i == n + 1) i = 1;   // 右哨兵索引到跳转到头部
        if (a[i] == 0) k--;
        if (k != 0) {
          ++i;
        } else {break;}
      }
      for (;;) {
        if (j == 0) j = n;    // 左哨兵索引跳转到尾部
        if (a[j] == 0) m--;
        if (m != 0) {
          --j;
        } else { break;}
      }
      if (i == j) {
        a[i] = 1;
        (++cnt != n) ? printf("%3d,", i) : printf("%3d\n", i);
      } else {
        a[i] = 1; a[j] = 1;
        cnt += 2;
        (cnt != n) ? printf("%3d%3d,", i, j) : printf("%3d%3d\n", i, j);
      }
    }
  }
  return 0;
}
