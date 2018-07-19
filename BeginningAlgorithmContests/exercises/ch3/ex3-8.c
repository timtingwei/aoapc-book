// copyright [2018] <mituh>
// UVa 202 - Repeating Decimals
/*
  思路:
  a / b = intg0...m0, a(m0) * 10 / b = intg1...m1, 将每个intg, m存入对应int数组
  当出现mi与之前所出现的m重复时, 记录i, ib, 长度为 i - ib;
  cycle为 a_intg[ib] - > a_ing[i]
*/

#include <stdio.h>
int a_intg[1024];
int a_m[1024];

int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  printf("%f, a mod b = %d\n", a/(double)b, a % b);
  int ie = 0, ib = 0, find = 0;
  for (;;) {
    a_intg[ie] = a / b;
    a_m[ie] = a % b;
    for (int j = 0; j < ie; j++) {
      if (a_m[ie] == a_m[j]) {
        find = 1;
        ib = j;    // 第一次出现重复  -> 也许可以在0~9的数字中优化
        break;
      }
    }
    if (find) break;  // 如果向前找到匹配, 结束
    a = a_m[ie] * 10;
    ie++;
  }

  // printf("%d/% = %\n");
  printf("%d %d, length = %d\n", ib, ie, ie - ib);
  for (int i = ib + 1; i <= ie; i++) {printf("%d", a_intg[i]);}
  printf("\n");
  for (int i = 0; i <= ib; i++) {printf("%d", a_intg[i]);}
  printf("\n");

  return 0;
}
