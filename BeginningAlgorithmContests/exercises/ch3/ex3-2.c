// copyright [2018] <mituh>
// Molar Mass, UVa1586(分子量)
/*
  思路: 统计按顺序依次出现的元素, 以及其个数

4
C
C6H5OH
NH2CH2COOH
C12H22O11

12.010
94.108
75.070
342.296
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

char s[85];
int foo1() {
  scanf("%s", s);
  float mass = 0.0, elem = 0.0;
  int i = 0;
  while (i < strlen(s)) {
    if (0 <= (s[i] - 'A') && (s[i] - 'A') <= 25) {  // 如果该字符是大写字母
      if (s[i] == 'C') {
        elem = 12.01;
      } else if (s[i] == 'H') {
        elem = 1.008;
      } else if (s[i] == 'O') {
        elem = 16.00;
      } else {
        elem = 14.01;
      }
      // 如果该字符是字母, 向后找数字求出数量
      int n = 0, cnt_n = 0;
      while (isdigit(s[++i])) {
        cnt_n++;
      }
      if (cnt_n == 0) {  // 如果字符后没有接数字, 该元素个数为1
        n = 1;
      } else if (cnt_n == 1) {
        n = s[i-1] - '0';
      } else {  // cnt_n = 2, 10 * s[i-2] + s[i-1]
        n = (s[i-2] - '0') * 10 + (s[i-1] - '0');
      }
      mass += (elem * n);
    }
  }
  printf("%.3f\n", mass);

  return 0;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    foo1();
  }

  return 0;
}
