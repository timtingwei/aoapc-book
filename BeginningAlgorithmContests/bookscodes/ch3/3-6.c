// copyright [2018] <mituh>

#include <stdio.h>
int main() {
  int c, i;
  char a[] = "1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
  while ((c = getchar()) != EOF) {
    for (i = 1; a[i] && a[i] != c; i++) {}
    if (a[i]) {
      putchar(a[i-1]);
    } else {
      putchar(c);
    }
  }
  printf("\n");

  return 0;
}
