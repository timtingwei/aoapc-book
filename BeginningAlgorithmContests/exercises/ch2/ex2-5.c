// copyright [2018] <mituh>
// convert to decimal
#include <stdio.h>
int main() {
  int a, b, c, kase = 1;
  while ((scanf("%d%d%d", &a, &b, &c) == 3) && a && b && c) {
    printf("Case %d: %d.", kase++, a/b);
    int i = 1;
    while (i < c) {
      a *= 10;
      printf("%d", a / b);
      a %= b;
      i++;
    }
    a *= 10;
    printf("%d\n", ((a % b * 10 / b >= 5) ? (a / b + 1) : (a / b)));
  }

  return 0;
}
