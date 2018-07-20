// copyright [2018] <mituh>
// 1588 - Kickdown(换抵挡装置)

#include <stdio.h>
#include <string.h>
#define MAXN 100 + 5

char a[MAXN] = {};
char b[MAXN] = {};
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("b.out", "w", stdout);
#endif
  while (scanf("%s %s", a, b) == 2) {
    if (strlen(b) > strlen(a)) {
      char ta[MAXN] = {};
      memcpy(ta, a, sizeof(a));
      memcpy(a, b, sizeof(b)); memcpy(b, ta, sizeof(ta));
    }
    int m = strlen(a), n = strlen(b);
    int ib = 0, ie = 0, min_l = m + n;
    while (ib < m + 1) {
      // printf("-- ib = %d, ie = %d\n", ib, ie);
      int ok = 1;
      for (int i = 0; i < ie - ib; i++) {
        if (ie < n) {
          if (a[ib+i] + b[n-(ie-ib)+i] == 100) { ok = 0; break; }
        } else {
          if (a[ib+i] + b[i] == 100) { ok = 0; break; }   // ascii('2') = 50
        }
      }
      if (ok) {
        int len = n - (ie - ib) + m;
        min_l = (len < min_l) ? len : min_l;
        // printf("ib = %d, ie = %d, len = %d --\n", ib, ie, len);
      }
      if (ie >= n) ib++;
      if (ib <= m - n) ie++;
    }
    printf("%d\n", min_l);
  }

  return 0;
}
