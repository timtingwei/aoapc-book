// copyright [2018] <mituh>
// 4-1 计算组合数

#include <stdio.h>

int C(int n, int m) {
  if (m < n-m) m = n-m;    // why? m = n - m; n - m = n - (n - m ) = m;
  long long ans = 1;
  for (int i = m+1; i <= n; i++) ans *= i;
  for (int i = 1; i <= n-m; i++) ans /= i;
  return ans;
}

int main() {
  int n, m;
  if (scanf("%d %d", &n, &m) == 2) {
    printf("%d\n", C(n, m));
  }
  return 0;
}
