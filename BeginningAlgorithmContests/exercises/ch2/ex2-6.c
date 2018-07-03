// copyright [2018] <mituh>
// permutation

// 使用数组保存各个位数被占用的计数
#include <stdio.h>
int main() {
  for (int a = 123; a < 329; a++) {
    int cnt[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int a1 = a/100, a2 = a/10%10, a3 = a%10;
    if (a1 == a2 || a2 == a3 || a1 == a3) {
      continue;
    } else {
      int b = 2*a, c = 3*a;
      int b1 = b/100, b2 = b/10%10, b3 = b%10;
      int c1 = c/100, c2 = c/10%10, c3 = c%10;
      if (b1 == b2 || b2 == b3 || b1 == b3 || b1 == 0 || b2 == 0 || b3 == 0) continue;
      if (c1 == c2 || c2 == c3 || b1 == b3 || c1 == 0 || c2 == 0 || c3 == 0) continue;
      if (++cnt[a1] == 1 && ++cnt[a2] == 1 && ++cnt[a3] == 1
          && ++cnt[b1] == 1 && ++cnt[b2] == 1 && ++cnt[b3] == 1
          && ++cnt[c1] == 1 && ++cnt[c2] == 1 && ++cnt[c3] == 1) {
        printf("%d %d %d\n", a, b, c);
      }
    }
  }
}

