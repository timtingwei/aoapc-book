// copyright [2018] <mituh>
// Palindromes, uVa401
// 为reverse char写函数, 而不是直接写对应的常量数组
// 用到ctype中的isaplha, 另外还可以使用isdigit, isprint, toupper, tolower

#include <stdio.h>
#include <string.h>
#include <ctype.h>

char a[1000];
const char rev[] = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
const char* msg[] = {"not a palindrome.", "a mirrored string.",
                     "is a regular palindrome.", "is a mirrored palindrome."};

char r(char ch) {
  if (isalpha(ch)) {
    return rev[ch - 'A'];
  } else {
    return rev[ch - '1' + 25];
  }
}

int main() {
  while (scanf("%s", a) == 1) {
    int len = strlen(a), p = 1, m = 1;
    for (int i = 0; i < len; i++) {
      if (a[i] != a[len - 1 - i]) p = 0;
      if (r(a[i]) != a[len - 1 - i]) m = 0;
    }
    printf("%s -- is %s\n", a, msg[p*2 + m]);
  }
}
