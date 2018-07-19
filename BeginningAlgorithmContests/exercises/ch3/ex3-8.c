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
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("b.out", "w", stdout);
#endif
  int a, b, kase = 0;
  while (scanf("%d %d", &a, &b) == 2) {
    if (++kase != 1) printf("\n");
    printf("%d/%d = ", a, b);
    int ie = 0, ib = 0, find = 0, id = 1;
    int t = a / b;
    while ((t /= 10) > 0) {
      id++;  // 标记顿号位置
    }
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


    if ((ie - ib) <= 50) {
      for (int i = 0; i <= ie; i++) {
        if (i == id) putchar('.');
        if (i == ib+1) putchar('(');
        printf("%d", a_intg[i]);
        if (i == ie) putchar(')');
      }
    } else {
      for (int i = 0; i <= id + 49; i++) {
        if (i == id) putchar('.');
        if (i == ib+1) putchar('(');
        printf("%d", a_intg[i]);
        if (i == id + 49) printf("...)");
      }
    }
    printf("\n");
    printf("%4d = number of digits in repeating cycle\n", ie - ib);
  }


  return 0;
}


/*
41/468 = 0.08(760683)
   6 = number of digits in repeating cycle

1169/725 = 1.61(2413793103448275862068965517)
   28 = number of digits in repeating cycle

2962/465 = 6.3(698924731182795)
*/
