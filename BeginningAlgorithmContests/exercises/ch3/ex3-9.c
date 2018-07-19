// copyright [2018] <mituh>
// UVa 10340 - All in All(子序列)
/*
  思路:
  1, 对s中从左到右每个字符在t中的索引, 前一个索引必须小于后一个 // error? 对应关系不确定
  2, 从左到右遍历s中每个字符, 找到si在t中对应索引ti, 更新下一次开始索引为ti+1, 找不到返回no, 遍历完打印yes
*/

#include <stdio.h>
#include <string.h>
#define MAXN 100000 + 10

char t[MAXN];
char s[MAXN];

int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("b.out", "w", stdout);
#endif
  while ((scanf("%s %s", s, t)) == 2) {
    int n = strlen(s), m = strlen(t);
    int pos = 0, ok = 1;
    for (int i = 0; i < n; i++) {
      int find = 0;
      while (!find && pos < m) {
        // 从pos位置向后找
        if (s[i] == t[pos]) {
          // 找到对应字符
          find = !find;
          pos++;
          break;
        }
        pos++;
      }
      if (!find) { printf("No\n"); ok = !ok; break; }
    }
    if (ok) printf("Yes\n");
  }

  return 0;
}

