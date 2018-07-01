#include <stdio.h>
int main() {
  for (int i = 1; ; i++) {
    int n = i * i;
    if (n < 1000) continue;
    if (n > 9999) break;
    int hi = n / 100;
    int lo = n % 100;
    if (hi % 11 == 0 && (lo == 0 || lo % 11 == 0)) {
      printf("%d\n", n);
    }
    // if ((hi / 10 == hi % 10) && (lo / 10 == lo % 10))
    // printf("%d %d %d \n %d %d %d %d \n \n", n, hi, lo, hi/10, hi%10, lo/10, lo%10);
  }

  return 0;
}
