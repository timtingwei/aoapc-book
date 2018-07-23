// copyright [2018] <mituh>
// UVa 213 Message Decoding(信息解码)
/*
Sample input
TNM AEIOU
0010101100011
1010001001110110011
11000
$#**\
0100000101101100011100101000
Sample output
TAN ME ##
*\$*(\)

*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAXN 100    // 字符串长度
#define MAXM 100   // 编码文本长度
#define MAXD 150    // 解码字符串长度
char s1[MAXN];     /* S#**\ */
char s2[MAXM];  // 0100000101101100011100101000
char s3[MAXN][MAXD];   // 0 00 01 10 000 010 011 100 0000 ..
char ans_s[MAXN];     // 输出
int N;


void generate_s3(int n) {
  // 生成奇怪的二进制字符串
  int b = 1, cnt = 0;
  for (;;) {
    int bad = 0;
    for (int i = 0; (i < ((1 << b)-1)); i++) {  // ^比-的优先级低 ^是位异运算符
      char st[10] = {};
      memset(st, '0', sizeof(char) * b);
      int j = b-1, k = i;
      do {
        // 二进制转换, 直到取余后的整数部分为0
        st[j--] = (k == 0) ? '0' : '0' + k % 2;  // 注意别用整数给字符赋值
        k /= 2;
      } while (k);
      for (int x = 0; x < b; x++) { s3[cnt][x] = st[x];}
      cnt++;
      if (cnt == n) {bad = 1; break;}
    }
    if (bad) break;
    b++;  // 改变位数(阶段)
  }
  // printf("cnt  = %d, n = %d\n", cnt, n);
  // printf("    s3 = \n");
  // for (int i = 0; i < cnt; i++) printf("      %s\n", s3[i]);
}

int btoi(int* a, int n) {
  // 将二进制转化成十进制, 3位限制
  return ((a[0]*2) + a[1]) * 2 + a[2];
}

int compare(char (*s)[MAXD], int n, char* s2) {
  // 在互不重复长度为n的字符串数组s中, 找到s2, 返回s2在s中的索引
  int p = 0, find = 0;
  for (int i = 0; i < n; i++) {
    if (strlen(s[i]) == strlen(s2)) {
      int bad = 0;
      for (int j = 0; j < strlen(s[i]); j++) {
        if (s[i][j] != s2[j]) {bad = 1; break;}
      }
      if (!bad) {p = i; find = 1; break;}
    }
  }
  if (find) {
    return p;
  } else { return -1;}
}

int find_in_s(int* a, int n) {
  // 在s3中找数组a对应索引, 数组a全1返回-1, 当心找存在意外的数
  int all_one = 1;
  char find_s[MAXD] = {};  // 将整数转化为字符串
  for (int i = 0; i < n; i++) {
    find_s[i] = a[i] + '0';
    if (a[i] != 1) all_one = 0;
  }
  if (all_one) {return -1;}
  int find = compare(s3, N, find_s);   // 大小为N的s3中, 找find_s索引, 没找到-1
  // printf("find = %d\n", find);
  /*
  for (int i = 0; i < n; i++)
    if (find_s == s3[i]) {find = i; break;}   // 不同字符串之间, 不能单纯的比较
  */
  if (find != -1) {
    return find;
  } else { printf("error in find_in_s \n"); return -1;}

  printf("error maye return 0!!\n");
  return 0;
}

int go(int* p, int t, int st) {
  int step_a[5] = {};    // 目前题目给定是3, t改变可能出错
  int ans = 0;
  for (int i = 0; i < t; i++) { step_a[i] = s2[(*p)+i] - '0';}
  (*p) += t;
  if (st == 0) {
    ans = btoi(step_a, t);     // 将二进制转换成十进制, 作为符号索引
  } else if (st == 1) {
    ans = find_in_s(step_a, t);  // 在s3中找step_a对应的索引
  }

  return ans;
}

/*
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
#endif
  if (scanf("%s %s", s1, s2) == 2) {
    //
    int n = strlen(s2);
    N = strlen(s1);   // 传递到全局变量
    generate_s3(N);  // 生成s3
    int cnt = 0;
    int p = 0, t = 3, st = 0;   // 当前位置, 步长, 状态:先找编码长度
    while (p < n) {
      if (!st) {  // 找出编码长度
        t = go(&p, t, 0);
        st = 1;
      } else {   // s=1, 寻找对应长度的解码字母, 以及结束字母
        int si = 0;
        si = go(&p, t, 1);
        if (si != -1) {  // 不是结束字符
          ans_s[cnt++] = s1[si];
        } else { t = 3; st = 0;}
      }
    }
    printf("%s\n", ans_s);
  }
  return 0;
}
*/


int decode() {
  // 解码当前的s1, s2
  // 每次解码前清空s1, s2, s3数组, 以及答案
  // memset(s1, '\0', sizeof(s1));
  // memset(s2, '\0', sizeof(s2));
  memset(s3, '\0', sizeof(s3));
  // memset(ans_s, '\0', sizeof(ans_s));
  int n = strlen(s2);
  N = strlen(s1);   // 传递到全局变量
  generate_s3(N);  // 生成s3
  int cnt = 0;
  int p = 0, t = 3, st = 0;   // 当前位置, 步长, 状态:先找编码长度
  while (p < n) {
    if (!st) {  // 找出编码长度
      t = go(&p, t, 0);
      st = 1;
    } else {   // s=1, 寻找对应长度的解码字母, 以及结束字母
      int si = 0;
      si = go(&p, t, 1);
      if (si != -1) {  // 不是结束字符
        // printf("si = %d\n", si);
        ans_s[cnt++] = s1[si];
      } else { t = 3; st = 0;}
    }
  }
  printf("%s\n", ans_s);

  return 0;
}
/*
s1 = $ #  *  *  \
     0 00 01 10 000
     0 1  2  3  4
s2 = 010 00 00 10 11  011 000 111 001 0 1  000
     (2) 1  1  3  \n  (3) 4   \n  (1) 0 \n
*/


int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
#endif
  /*
  整体用getchar读入所有字符, 每次读入一个c时,
  if (st= 0) 时,
    if (读到'\n') {s2[n2++] = c, st -> 1;}
    else s1[n1++] = c;
  if (st = 1) 时
    if (读到除了'0', '1', '\n'以外的字符) {
      st -> 0; 进行一次解码; 清空数组;
      if (c == EOF) {break;退出循环}
    }
    else s2[n2++] = c;
  */
  int c = 0, n1 = 0, n2 = 0, st = 0;
  memset(s1, '\0', sizeof(s1));
  memset(s2, '\0', sizeof(s2));
  for (;;) {
    c = getchar();
    if (st == 0) {
      if (c == '\n') {
        st = 1;
      } else {  // 代码里, c是除了'\n'以外的字符, 实际上我要求的是字母字符
        // printf("s1[%d] = %c\n", n1, c);
        s1[n1++] = c;
      }
    } else if (st == 1) {
      if (c == '0' || c == '1' || c == '\n') {
        if (c == '0' || c == '1') {
          // printf("s2[%d] = %c\n", n2, c);
          s2[n2++] = c;
        }
      } else {  // 读s2的时候, 读到0,1,\n以外的字符
        st = 0;
        // printf("s1 = %s\n  s2 = %s\n", s1, s2);
        decode();
        memset(s1, '\0', sizeof(s1));
        memset(s2, '\0', sizeof(s2));
        memset(ans_s, '\0', sizeof(ans_s));
        n1 = 0, n2 = 0;
        // printf("add s1[%d] = %c\n", n1, c);
        s1[n1++] = c;
        if (c == EOF) { break;}
      }
    }
  }
  return 0;
}


int foo() {
  int n = 4;
  generate_s3(n);

  return 0;
}
