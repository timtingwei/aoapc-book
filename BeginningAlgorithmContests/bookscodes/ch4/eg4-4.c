// copyright [2018] <mituh>
// UVa 213 Message Decoding(信息解码)
/*
S#**\
0100000101101100011100101000
*/
#include <stdio.h>
#include <string.h>
#define MAXN 100    // 字符串长度
#define MAXM 100   // 编码文本长度
#define MAXD 150    // 解码字符串长度
char s1[MAXN];     /* S#**\ */
char s2[MAXM];  // 0100000101101100011100101000
char s3[MAXN][MAXD];   // 0 00 01 10 000 010 011 100 0000 ..
char ans_s[MAXN];     // 输出



void generate_s3(int n) {
  // 生成奇怪的二进制字符串
  int b = 1, cnt = 0;
  while (cnt <= n) {
    for (int i = 0; i < ((1 << b)-1); i++) {  // ^比-的优先级低 ^是位异运算符
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
    }
    b++;  // 改变位数
  }
  for (int i = 0; i < cnt; i++) printf("%s\n", s3[i]);
  printf("%d\n", cnt);
}

int btoi(int* a, int n) {
  // 将二进制转化成十进制, 3位限制
  return ((a[0]*2) + a[1]) * 2 + a[2];
}

int find_in_s(int* a, int n) {
  // 在s3中找数组a对应索引, 数组a全1返回-1, 当心找存在意外的数
  int all_one = 1;
  char find_s[MAXD] = {};  // 将整数转化为字符串
  for (int i = 0; i < n; i++) {
    find_s[i] = a[i] + '0';
    if (a[i] != 1) all_one = 0;
  }
  if (all_one) { printf("all one!! return\n"); return -1; }
  int find = -1;
  for (int i = 0; i < n; i++)
    if (find_s == s3[i]) {find = i; break;}   // 不同字符串之间, 不能单纯的比较
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

int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
#endif
  if (scanf("%s %s", s1, s2) == 2) {
    //
    int n = strlen(s1);
    generate_s3(n);  // 生成s3
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
  }
  return 0;
}
