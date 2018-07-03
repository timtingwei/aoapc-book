// copyright [2018] <mituh>
// 1, memset设置数组初始值
// 2, ! 取反运算符
// 3, 无{}else, 与向前最近if配对, 且只包括一个分号行
// 4, 标准输出时, 中间空格, 结尾换行, first

#include <stdio.h>
#include <string.h>
#define MAXN 10000
int arr[MAXN];
int main() {
  int n, k, first = 1;
  scanf("%d%d", &n, &k);
  memset(arr, 0, sizeof(arr));         // off
  for (int i = 1; i <= k; i++) {
    for (int j = 1; j <= n; j++) {
      arr[j*i] = !arr[j*i];            // change toggle
    }
  }
  for (int i = 1; i <= n; i++) {
    if (arr[i]) { if (first) first = 0; else printf(" "); printf("%d", i); }
  }
  printf("\n");

  return 0;
}
