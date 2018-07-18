// copyright [2018] <mituh>
// UVa1368 - DNA Consensus String(DNA序列)
/*
  思路:
    1, 遍历每个dna序列, 求出它与其他序列的hamming总和sum_i, 存入数组a_sum
    2, 选中a_sum中最大的值对应序列
    3, 遍历这些序列中, 得到字典序最小值序列
*/

#include <stdio.h>
#include <string.h>
#define MAXM 50 + 5
#define MAXN 1000 + 20
char s_dna[MAXN][MAXM];  // m个长度为n的字符串序列数组
int a_sum[MAXN];         // 保存不同序列的hamming值之和

int main() {
  int m, n;
  scanf("%d%d", &m, &n);
  // 输入dna序列
  for (int i = 0; i < m; i++) {scanf("%s", s_dna[i]);}
  printf("%d\n", strlen(s_dna[0]));

  // 遍历序列, 求出每个序列相对其他序列的hamming总和
  for (int i = 0; i < m; i++) {
    int sum = 0;
    for (int j = 0; j < m; j++) {
      if (j == i) continue;  // 比较的序列是自己本身, 忽略不计
      for (int x = 0; x < n; x++) {
        if (s_dna[i][x] != s_dna[j][x]) sum++;
        printf("%c %c %d\n", s_dna[i][x], s_dna[j][x], sum);
      }
    }
    a_sum[i] = sum;
  }

  // 选出a_sum中最大值对应序列, 只保留索引
  int max_i[MAXN] = {};
  int cnt = 1;   // 最大值索引个数
  max_i[0] = 0;  // 假设序列索引0为此时hamming最大, 并存入所有最大值索引数组
  for (int i = 1; i < m; i++) {
    if (a_sum[i] == a_sum[max_i[0]]) {
      // 相等
      max_i[cnt++] = i;  // 当前索引加入最大值索引数组
    } else if (a_sum[i] > a_sum[max_i[0]]) {
      // 当前索引对应的比之前存的大, 用当前索引替换所有在数组中的值
      memset(max_i, 0, sizeof(max_i));
      cnt = 1;
      max_i[0] = i;
    }
  }

  // 遍历这些序列中, 得到字典序最小值序列
  char s_r[MAXN] = s_dna[max_i[0]];
  for (int i = 1; i < cnt; i++) {
    if (dict_compare(s_dna[max_i[i]], s_r)) {
      // s_i的字典序比s_r小
      for (int j = 0; j < n; j++) {
        s_r[j] = s_dna[max_i[i]][j];
      }
    }
  }

  printf("%s\n", s_r);


  return 0;
}

/*
5 8
TATGATAC
TAAGCTAC
AAAGATCC
TGAGATAC
TAAGATGT
*/
