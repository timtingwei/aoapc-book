#include <stdio.h>
int main() {
  long long n, m;
  int kase = 1;
  while (scanf("%lld%lld", &n, &m) == 2 && n && m) {
    double s = 0;
    while (n <= m) {
      s += 1.0/(n*n);
      n++;
    }
    printf("Case %d: %.5f\n", kase++, s);
  }

  return 0;
}
