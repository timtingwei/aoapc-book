// copyright [2018] <mituh>
// 4-7 计算数组元素和(有问题)

#include <stdio.h>
int sum(int a[]) {
  int ans = 0;
  for (int i = 0; i < sizeof(a); i++)  // 传入的是首个元素地址, 无法得到数组大小
    sum += a[i];
  return ans;
}

int main() {
  // ..
  int a[] = {1, 2, 3};
  printf("%d\n", sum(a));
  return 0;
}
