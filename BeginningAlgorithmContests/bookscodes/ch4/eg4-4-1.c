// copyright [2018]
// UVa 213 Message Decoding(信息解码) - 课本参考
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
int readchar() {
  for (;;) {
    int ch = getchar();
    if (ch != '\n' && ch != '\r') return ch;   // 一直读到非换行符为止
  }
}
int readint(int c) {
  int v = 0;
  while (c--) v = v * 2 + readchar() - '0';
  return v;
}

int code[8][1<<8];
int readcodes() {
  memset(code, 0, sizeof(code));  // 清空数组
  code[1][0] = readchar();  // 直接跳到下一行开始读取, 如果输入已经结束, 会读到EOF
  for (int len = 2; len <= 7; len++) {
    for (int i = 0; i < (1 << len) - 1; i++) {
      int ch = getchar();
      if (ch == EOF) return 0;
      if (ch == '\n' || ch == 'r') return 1;
      code[len][i] = ch;
    }
  }
  return 1;
}

void printcodes() {
  for (int len = 1; len <= 7; len++)
    for (int i = 0; i < (1 << len) - 1; i++) {
      if (code[len][i] == 0) return;
      printf("code[%d][%d] = %c\n", len, i, code[len][i]);
    }
}

int main() {
  while (readcodes()) {  // 无法读取更多编码头退出
// printcodes();
    for (;;) {
      int len = readint(3);
      if (len == 0) break;
// printf("len = %d\n", len);
      for (;;) {
        int v = readint(len);
// printf("v=%d\n", v);
        if (v == (1 << len)-1) break;
        putchar(code[len][v]);
      }
    }
    putchar('\n');
  }

  return 0;
}
