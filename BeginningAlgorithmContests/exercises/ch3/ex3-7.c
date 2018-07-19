// copyright [2018] <mituh>
// UVa1368 - DNA Consensus String(DNA序列)
/*
  思路:
    1, 遍历每个dna序列, 求出它与其他序列的hamming总和sum_i, 存入数组a_sum
    2, 选中a_sum中最小的值对应序列
    3, 遍历这些序列中, 得到字典序最小值序列
*/

#include <stdio.h>
#include <string.h>
#define MAXM 50 + 5
#define MAXN 1000 + 20
char s_dna[MAXN][MAXM];  // m个长度为n的字符串序列数组
int a_sum[MAXN];         // 保存不同序列的hamming值之和

int dict_compare(const char (*s1)[MAXM], const int p, const int q) {
  // s1的字典序比s2小, 返回true
  int n = strlen(s1[0]);
  for (int i = 0; i < n; i++) {
    if (s1[p][i] == s1[q][i]) {
      continue;
    } else {
      return s1[p][i] < s1[q][i];
    }
  }
  return 0;  // 字典序列相等
}

int foo() {
  int m, n;
  scanf("%d%d", &m, &n);
  // 输入dna序列
  for (int i = 0; i < m; i++) {scanf("%s", s_dna[i]);}
  // printf("%lu\n", strlen(s_dna[0]));

  // 遍历序列, 求出每个序列相对其他序列的hamming总和
  for (int i = 0; i < m; i++) {
    int sum = 0;
    for (int j = 0; j < m; j++) {
      if (j == i) continue;  // 比较的序列是自己本身, 忽略不计
      for (int x = 0; x < n; x++) {
        if (s_dna[i][x] != s_dna[j][x]) sum++;
        // printf("-- %c %c %d\n", s_dna[i][x], s_dna[j][x], sum);
      }
      // printf("        --\n");
    }
    a_sum[i] = sum;
    // printf("  i = %d, sum = %d\n", i, sum);
  }

  // 选出a_sum中最小值对应序列, 只保留索引
  int min_i[MAXN] = {};
  int cnt = 1;   // 最小值索引个数
  min_i[0] = 0;  // 假设序列索引0为此时hamming最小, 并存入所有最小值索引数组
  for (int i = 1; i < m; i++) {
    if (a_sum[i] == a_sum[min_i[0]]) {
      // 相等
      min_i[cnt++] = i;  // 当前索引加入最小值索引数组
    } else if (a_sum[i] < a_sum[min_i[0]]) {
      // 当前索引对应的比之前存的大, 用当前索引替换所有在数组中的值
      memset(min_i, 0, sizeof(min_i));
      cnt = 1;
      min_i[0] = i;
    }
  }
  // for (int i = 0; i < cnt; i++) {printf("    min_i[%d] = %d\n", i, min_i[i]);}

  // 遍历这些序列中, 得到字典序最小值序列 索引i_r
  int i_r = min_i[0];
  for (int i = 1; i < cnt; i++) {
    if (dict_compare(s_dna, min_i[i], i_r)) {
      // s_i的字典序比s_r小
      i_r = min_i[i];
    }
  }
  printf("%s\n%d\n", s_dna[i_r], a_sum[i_r]);
  return 0;
}

int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("b.out", "w", stdout);
#endif
  int T;
  scanf("%d", &T);
  while (T--) {
    foo();
  }

  return 0;
}

/*
1
5 8
TATGATAC 11011111 = 7
TAAGCTAC 11110111 = 7
AAAGATCC 01111101 = 6
TGAGATAC 10111111 = 7
TAAGATGT 11111100 = 6

22212032
11101021 = 7

TAAGATAC
7


4 10 
ACGTACGTAC 1111111111 
CCGTACGTAG 1111111111
GCGTACGTAT 1111111111
TCGTACGTAA 1111111111

1
5 8
TATGATAC
TAAGCTAC
AAAGATCC
TGAGATAC
TAAGATGT


4 10
ACGTACGTAC
CCGTACGTAG
GCGTACGTAT
TCGTACGTAA

ACGTACGTAA
6


6 10
ATGTTACCAT
AAGTTACGAT
AACAAAGCAA
AAGTTACCTT
AAGTTACCAA
TACTTACCAA

AAGTTACCAA
12


TAAGATAC
7
ACGTACGTAA
6
AAGTTACCAA
12

AGCAT
10210 = 4
AGACT
10120 = 4
GGAAT
20110 = 4

*/

