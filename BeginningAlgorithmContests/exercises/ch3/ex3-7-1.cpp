// copyright [2018] <mituh>
// UVa1368 - DNA Consensus String(DNA序列)
/*
  思路:
  1, 统计每个位置出现次数最多的字符, 使得hamming距离总和最短
  2, 多个序列同时满足时, 讨论字典序
*/

#include <stdio.h>
#include <algorithm>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    char DNA[64][1024];
    int n, m;  // n个序列, 每个序列m个字符
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
      scanf("%s", DNA[i]);
    int hh = 0;
    char ret[1024] = {}, cc[] = "ACGT";
    for (int i = 0; i < m; i++) {
      int cnt[4] = {}, mx = 0;
      for (int j = 0; j < n; j++) {
        // 在列数一定时, 遍历行数
        cnt[std::find(cc, cc+4, DNA[j][i]) - cc]++;  // i位置各字符出现次数
      }

      for (int j = 0; j < 4; j++) {
        if (cnt[j] > cnt[mx])
          mx = j;  // 出现最多的字符索引
      }

      ret[i] = cc[mx], hh += n - cnt[mx];  // 出现最多字符, 累计同位置的不同个数
    }
    printf("%s\n%d\n", ret, hh);
  }

  return 0;
}
