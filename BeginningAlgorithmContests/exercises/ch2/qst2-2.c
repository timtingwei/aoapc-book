// copyright [2018] <mituh>
// int to double precision
// test redirection I/O

#include <stdio.h>
int main() {
#ifdef LOCAL
  freopen("input.in", "r", stdin);
  freopen("output.out", "w", stdout);
#endif
  int n;
  scanf("%d", &n);
  double i;
  for (i = 0; !(n - i < 0.0001); i += 0.1) {
    printf("%.1f\n", i);
  }

  return 0;
}
