// copyright [2018] <mituh>
// Periodic string, UVa455(周期串)
/*
  s[i] ?= s[i+k] ?= s[i+2k], i = 0, 1, 2 ... k-1; k <=40;
 */

#include <stdio.h>
#include <string.h>
#define MAXN 80 + 5
char s[MAXN];

int foo() {
  scanf("%s", s);
  int n = strlen(s);
  for (int k = 1; k <= n; k++) {
    int ok = 1;
    for (int i = 0; i < k; i++) {
      int t = k;
      while (t < n) {
        if (s[i] != s[i+t]) {ok = 0; break;}
        t += k;
      }
      if (!ok) break;
    }
    if (ok) {printf("%d\n", k); break;}
  }

  return 0;
}

int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("b.out", "w", stdout);
#endif
  int T;
  scanf("%d", &T);
  while (T) {
    foo();
    if (T != 1) {printf("\n");}
    T--;
  }

  return 0;
}
