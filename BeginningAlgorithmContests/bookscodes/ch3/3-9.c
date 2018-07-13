// copyright [2018] <mituh>
/*
Digital Generator, UVa 1583
如果x加上x的各个数字之和得到y, 就说x是y的生成元. 给出n(1 <= n <= 100000), 求最小生成元, 无解输出为0
input:
n = 216, 121, 2005
output:
198, 0, 1979

数组存储不连续的生成元生成的y作为索引 memset(ans, 0, sizeof(ans)), y对应的生成元可以比较大小, y对应值为0时, 自然不存在生成元 
*/
#include <stdio.h>
#include <string.h>
#define MAXN 100005
int ans[MAXN];

int main() {
  // 计算出1～100000每数作为生成元得到的结果, 储存在数组中f
  memset(ans, 0, sizeof(ans));
  for (int g = 1; g < MAXN; g++) {
    int x = g, y = g;
    // 原本的值, 加上各个位数的累加
    while (x > 0) {
       y += x % 10;
       x /= 10;
    }
    if (ans[y] == 0 || g < ans[y]) ans[y] = g;
  }

  int n, T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    // 当结果已知时, 得到生成元
    printf("%d\n", ans[n]);
  }
  return 0;
}
