// copyright [2018] <mituh>
// 4-03 判定素数(有问题)
/*
  只能被1和其自身整除的数
*/

#include <stdio.h>
#include <math.h>

int is_prime(int n) {
  int m = sqrt(n);
  for (int i = 2; i <= m; i++) {
    if ((n%i) == 0) return 0;
  }
  return 1;
}

int main() {
  int n;
  while (scanf("%d", &n) == 1) {
    printf("%d\n", is_prime(n));
  }
  return 0;
}
