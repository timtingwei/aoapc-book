// copyright [2018] <mituh>
// UVa 133, The Dole Queue(救济金发放)
#include <stdio.h>
int a[25], n, k, m;

int go(int p, int d, int t) {
  // p当前位置, d顺逆时针, d=1逆, d=-1顺, t代表总共走多少步
  while (t--) {
    do {p = (p+d+n-1)%n + 1;} while (a[p] == 0);  // why?
  }
  return p;
}

int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("b.out", "w", stdout);
#endif
  while (scanf("%d %d %d", &n, &k, &m) == 3 && n) {
    for (int i = 1; i <= n; i++) a[i] = i;
    int left = n;
    int p1 = n, p2 = 1;  // why?
    while (left) {
      p1 = go(p1, 1,  k);
      p2 = go(p2, -1, m);
      printf("%3d", p1); left--;
      if (p1 != p2) { printf("%3d", p2); left--;}
      a[p1] = a[p2] = 0;
      if (left) putchar(',');
    }
    printf("\n");
  }

  return 0;
}
