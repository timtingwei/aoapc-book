// copyright [2018]
// UVa 213 Message Decoding(信息解码) - 课本参考(存在bug)
// bug: 编码000结尾而前面无全111
/*
Sample input

TNM AEIOU
0010101100011
1010001001110110011
11000
$#**\
[010] 00 00 10 (11) [011] 000 (111) [001] 0 (1) 000

Sample output
TAN ME
##*\$

*/

#include <stdio.h>
#include <string.h>
int readchar() {
  for (;;) {
    int ch = getchar();
    if (ch != '\n' && ch != '\r') return ch;
  }
  return 0;
}

int readint(int c) {
  // 将读到的二进制转化成十进制索引
  int v = 0;
  while (c--) v = v * 2 + readchar() - '0';
  return v;
}

int codes[8][1 << 8];
int readcodes() {
  memset(codes, 0, sizeof(codes));
  int ch = readchar();
  codes[1][0] = ch;   // 直接开始读下一行, EOF时候结束
  for (int len = 2; len <= 7; len++) {
    for (int v = 0; v < (1 << len)-1; v++) {
      ch = getchar();
      if (ch == EOF) return 0;
      if (ch == '\n' || ch == 'r') return 1;
      codes[len][v] = ch;
    }
  }
  return 1;
}

void printcodes() {
  for (int len = 1; len <= 7; len++) {
    for (int v = 0; v < (1 << len) - 1; v++) {
      if (codes[len][v] == 0) return;
      printf("codes[%d][%d] = %c\n", len, v, codes[len][v]);
    }
  }
}


int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
#endif
  while (readcodes()) {
// printcodes();
    for (;;) {
      int len = readint(3);
// printf("  len=%d\n", len);
      if (len == 0) break;  // 000
      for (;;) {
        int v = readint(len);
// printf("  v=%d\n", v);
        if (v == (1 << len) - 1) break;  // 全1, 存在bug, 如果直接以000结尾
        putchar(codes[len][v]);
      }
    }
    putchar('\n');   // printf("\n");
  }
  return 0;
}

/*
直接以000结尾的bug:
debug Sample:
ABCDEFG
0010101000011011011000001010000
AAAAAAA
0010101000011011011000001010000
ABCDEFG
001000000000101001010101000
ABCDEFG
001000
00000
0101001010
10111000


ABCDEFG
001 (0) 1 [010] 00 01 10 (11) [011] 000 001 010 000
AAAAAAA
0010101000011011011000001010000
ABCDEFG
[001] 0 (1) [010] 00 01 10 (11) [011] 000 001 010 [000]
AAAAAAA
[001] 0 (1) [010] 00 01 10 (11) [011] 000 001 010 [000]
ABCDEFG
001000000000101001010101000
ABCDEFG
[001] 0 0 0 0 0 0 0 0 0 (1) [010] 01 01 01 01 (11) [000]
*/
