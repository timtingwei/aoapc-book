// copyright [2018] <mituh>
// 232 - Crossword Answers(纵横字谜的答案)
/*
  思路:遍历的同时, 存储编号和字符串, 所遍历的字符, 分为三种类型
    1, '*' => continue
    2, 左边为'*' or ' ' => a[i][j-1] == '*' 向右遍历直到碰到'*' or ' ', 记录成cross字符串
    3, 上边为'*' or ' ' => a[i-1][j] == '*' 向下遍历直到碰到'*' or ' ', 记录成down字符串
  将边界memset成'*', ' '等价于'*'
*/
#include <stdio.h>
#include <string.h>

#define MAXN 100 + 10
char a[MAXN][MAXN];         // 标准输入字符的二维数组



int foo(const int r, const int c) {
  // 保存字符的数组置为0
  memset(a, '*', sizeof(a));
  // 将其他数组清空 why? 此时在声明成全局, 会在不同答案间互相干扰
  char cross[MAXN][MAXN] = {};     // 储存横向字符串的数组
  char down[MAXN][MAXN] = {};      // 储存纵向字符串的数组
  int c_i[MAXN] = {};              // 保存横向字符串索引
  int d_i[MAXN] = {};              // 保存纵向字符串索引
  for (int i = 1; i <= r; i++) {
    scanf("%s", a[i]);
    for (int j = c; j > 0; j--) {
      a[i][j] = a[i][j-1];
      // printf("%c ", a[i][j]);
    }
    a[i][0] = '*';
    // printf("\n");
  }
/*
  for (int i = 0; i <= r+1; i++) {
    for (int j = 0; j <= c+1; j++) {
      printf("%c", a[i][j]);
    }
    printf("\n");
  }
*/
  int cnt = 0, c_cnt = 0, d_cnt = 0;  // 起始格编号计数
  for (int i = 1; i <= r; i++) {
    for (int j = 1; j <= c; j++) {
      // 如果当前字符为'*', 不会成为起始格, 跳过
      if (a[i][j] == '*') continue;
      int have_cross = 0;    // 处理cross和down都存在的计数问题
      if (a[i][j-1] == '*') {
        // 左为'*', Cross字符串起始格
        have_cross = 1;
        int tmp = j, tmp_i = 0;
        while (a[i][tmp] != '*') {
          // 向右移动直到碰到'*'前
          // 向字符串cross[c_cnt]中写入字符
          cross[c_cnt][tmp_i++] = a[i][tmp];
          // printf("c = %c, s = %s\n", a[i][tmp], cross[c_cnt]);
          tmp++;
        }
        // printf("s = %s\n", cross[c_cnt]);
        c_i[c_cnt++] = ++cnt;   // 要对down进行处理 why?
        // printf("     c = %c, cnt = %d\n", a[i][j], cnt);
      }
      if (a[i-1][j] == '*') {
        // 上为'*', Down字符串起始格
        int tmp = i, tmp_i = 0;
        while (a[tmp][j] != '*') {
          // 向下移动直到碰到'*'前
          // 向字符串down[c_cnt]中写入字符
          down[d_cnt][tmp_i++] = a[tmp][j];
          // printf("c = %c, s = %s\n", a[tmp][j], down[d_cnt]);
          tmp++;
        }
        // printf("s = %s\n", down[c_cnt]);
        if (have_cross) {
          // 既是cross的起始格又是down的起始格
          d_i[d_cnt++] = cnt;  // 不会对cross和down都存在的字符重复计数
        } else {
          // 只存在down的情况
          d_i[d_cnt++] = ++cnt;
        }
        // printf("     c = %c, cnt = %d\n", a[i][j], cnt);
      }
    }
  }

  printf("Across\n");
  for (int i = 0; i < c_cnt; i++) {
    printf("%3d.%s\n", c_i[i], cross[i]);
  }
  printf("Down\n");
  for (int i = 0; i < d_cnt; i++) {
    printf("%3d.%s\n", d_i[i], down[i]);
  }

  return 0;
}

int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("b.out", "w", stdout);
#endif
  // 输入字符到二维数组
  int r, c, kase = 0;
  while (scanf("%d", &r) && (r != 0) && scanf("%d", &c)) {
    (kase == 0) ? printf("") : printf("\n");
    printf("puzzle #%d:\n", ++kase);
    foo(r, c);
  }

  return 0;
}


/*
9 9
*LAUREL**
PASSERINE
EST*CABER
WHOA*SETA
**UTTER**
LINT*RARE
INDIE*TON
INERTNESS
**DECODE*
*/

/*
2 2
AT
*O
6 7
AIM*DEN
*ME*ONE
UPON*TO
SO*ERIN
*SA*OR*
IES*DEA
0
*/
