// copyright [2018] <mituh>
// 4-8 计算数组元素和(正确)

#include <stdio.h>
int sum(int* a, int n) {  // 在函数调用时, 不一定只传入数组, 还可以传入地址
  int ans = 0;
  for (int i = 0; i < n; i++)
    ans += a[i];
  return ans;
}

int main() {
  // ..
  int n = 4;
  int a[] = {1, 2, 3, 4};
  printf("%d\n", sum(a + 1, 3));
  return 0;
}
