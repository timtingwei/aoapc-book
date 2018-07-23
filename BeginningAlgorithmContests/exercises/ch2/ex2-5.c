// copyright [2018] <mituh>
// 分数化小数(decimal) - 数组可进位版本
#include <stdio.h>
#define MAXN 100 + 5
int flt[MAXN];
int main() {
  int a, b, c, kase = 1;
  while ((scanf("%d%d%d", &a, &b, &c) == 3) && a && b && c) {
    int bi = a / b;  // 整数部分
    a = a - bi*b;    // 浮点数部分a初始值
    int cnt = 0, k = c + 1;
    while (k--) { a *= 10; flt[cnt++] = a / b; a %= b;}
    // 从第c开始判断, 保留4位, 从索引4开始判断, 取索引3作为输出
    if (flt[c] >= 5) {
      (flt[c-1])++;
      k = c-1;
      while (flt[k] == 10) {
        flt[k] = 0;
        if (k != 0) {
          flt[--k]++;
        } else {  // k是最开始的一位, 仍然需要进位
          bi++;   // 整数部分+1
          break;
        }
      }
    }  // <=4 无需管这个c+1, 因为四(舍)
    printf("Case %d: %d.", kase++, bi);
    for (int i = 0; i < c; i++) {printf("%d", flt[i]);}
    printf("\n");
  }

  return 0;
}

/*
Sample
$ ./a.out
1       6       4
9999    10000   4
9999    10000   3
99999   1000    3
99999   1000    2
1       17      3
1       17      4
6       73      4
Case 1: 0.1667
Case 2: 0.9999
Case 3: 1.000
Case 4: 99.999
Case 5: 100.00
Case 6: 0.059
Case 7: 0.0588
Case 8: 0.0822
*/
