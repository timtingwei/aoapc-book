// copyright [2018] <mituh>
/*
环状序列 Circular Sequence UVa1584
长度为n的环状序列有n种表示方法, 求字典序最小的"最小表示"
字典序, 对于两个字符串,
1, 从第一个字符开始比较, 当某一位置不同时, 该位置字符较小的串, 字典序较小; abc < bcd
2, 如果其中一个字符串已经没有更多字符串, 但另外一个还没有结束, 较短的字典序比较小 hi < history

思路:
1, 用ans索引表示一个字符串表示
2, ans记录当前最小表示

input: CGAGTCAGCT
output: AGCTCGAGTC
*/
#include <stdio.h>
#include <string.h>
#define MAXN 105

int less(const char* s, int p, int q) {
  // 比较环形串s, p表示与q表示, p比q字典序小, 返回1
  int n = strlen(s);
  for (int i = 0; i < n; i++) {
    if (s[(p+i) % n] != s[(q+i) % n]) {
      return s[(p+i) % n] < s[(q+i) % n];
    }
  }
  return 0;  // 相等
}

int main() {
  int T; char s[MAXN];
  scanf("%d", &T);
  while (T--) {
    scanf("%s", s);
    int n = strlen(s);
    int ans = 0;
    for (int i = 1; i < n; i++) {
      if (less(s, i, ans)) ans = i;
    }
    for (int i = 0; i < n; i++) {
      putchar(s[(i + ans) % n]);
    }
    putchar('\n');
  }

  return 0;
}
