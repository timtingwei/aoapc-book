// copyright [2018] <mituh>
// 4-10 用递归法计算阶乘
#include <stdio.h>
int fact(int n) {
  return (n == 0) ? 1 : n * fact(n-1);
}

int main() {
  int n = 10;
  printf("%d\n", fact(n));
  return 0;
}
