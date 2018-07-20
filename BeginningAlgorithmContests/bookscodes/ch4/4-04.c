// copyright [2018] <mituh>
// 4-04 判定素数
/*
  只能被1和其自身整除的数
  处理1和n过大的情况
*/

#include <stdio.h>
#include <math.h>

int is_prime(int n) {
  if (n <= 1) return 0;
  int m = floor(sqrt(n) + 0.5);
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
