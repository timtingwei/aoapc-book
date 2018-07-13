// copyright [2018] <mituh>
// Master-Mind Hints, UVa 340
/*
  给定答案序列和用户猜的序列, 统计有多少数字位置正确(A), 有多少数字在两个序列都出现过但位置不对(B)
  输入包含多组数据, 每组输入第一行为序列长度n, 第二行是答案序列, 接下来是若干猜测序列. 猜测序列全0时该组数据结束. n=0时输入结束.
  算法: 将答案和猜测保存在a, b数组中, A为两个数组索引对应相同的个数, 统计数组中0~9出现的次数, 分别为c1, c2, 得到min(c1, c2), B为min(c1, c2) - A
*/

#include <stdio.h>

#define maxn 10000
int main() {
#ifdef LOCAL
  freopen("input.in", "r", stdin);
  freopen("output.out", "w", stdout);
#endif
  int n, a[maxn], b[maxn];
  int kase = 0;
  while (scanf("%d", &n) && n) {
    printf("Game %d:\n", ++kase);
    for (int i = 0; i < n; i++) {scanf("%d", &a[i]);}
    for (;;) {
      int A = 0, B = 0;
      for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
        if (a[i] == b[i]) A++;
      }
      if (b[0] == 0) break;  // 不会出现0, 只要检查首个值是否为0, 判断全0序列
      for (int x = 1; x <= 9; x++) {
        int c1 = 0, c2 = 0;  // 统计x出现的次数
        for (int i = 0; i < n; i++) {
          if (a[i] == x) c1++;
          if (b[i] == x) c2++;
        }
        B = (c1 < c2) ? B + c1 : B + c2;
      }
      printf("    (%d,%d)\n", A, B-A);
    }
  }
  return 0;
}
