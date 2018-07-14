// copyright [2018] <mituh>
/*
环状序列 Circular Sequence UVa1584
长度为n的环状序列有n种表示方法, 求字典序最小的"最小表示"
字典序, 对于两个字符串,
1, 从第一个字符开始比较, 当某一位置不同时, 该位置字符较小的串, 字典序较小; abc < bcd
2, 如果其中一个字符串已经没有更多字符串, 但另外一个还没有结束, 较短的字典序比较小 hi < history

思路:
1, 用复制一遍数组, 递增首位索引的方法, 得到n个字符组成的字符串s的n个环状序列si
2, 每个序列si与当前最小序列min_s比较字典序, 更新最小的序列min_s

input: CGAGTCAGCT
output: AGCTCGAGTC
*/

#include <stdio.h>
#include <string.h>
#define MAXN 1000
char a[MAXN], s_min[MAXN];

int dict_smaller(char* s1, char* s2) {
  // 比较s1与s2的字典序, 如果s1 < s2, 返回1, 否则返回0
  int m1 = strlen(s1), m2 = strlen(s2);
  int n = (m1 < m2) ? m1 : m2;
  // 数量重合的序列部分
  for (int i = 0; i < n; i++) {
    if (s1[i] == s2[i]) continue;
    if (s1[i] < s2[i]) return 1; else return 0;
  }
  // 结束loop说明数量重合部分序列相同, 长度小的字典序小
  if (n == m1) return 1; else return 0;
}

/*
void test() {
  // function to test dict_smallmer(char*, char*)
  char a[] = "abc", b[] = "bcd", c[] = "history", d[] = "hi";
  int r1 = dict_smaller(a, b), r2 = dict_smaller(c, d);
  printf("%d %d\n", r1, r2);
}
*/


int main() {
  scanf("%s", a);
  int n = strlen(a);
  memcpy(s_min, a, sizeof(char) * n);
  // 用复制一遍数组, 递增首位索引的方法, 得到n个字符组成的字符串s的n个环状序列si
  for (int i = n; i < 2*n; i++) {a[i] = a[i - n];}
  for (int i = 1; i < n; i++) {
    char si[MAXN];
    for (int j = i; j < i + n; j++) {
      si[j-i] = a[j];
    }
    // 每个序列si与当前最小序列min_s比较字典序, 更新最小的序列min_s
    if (dict_smaller(si, s_min)) memcpy(s_min, si, sizeof(si));
  }
  printf("%s\n", s_min);

  return 0;
}

