#include <stdio.h>
int main() {
  int a, b, c, tmp;
  scanf("%d%d%d", &a, &b, &c);
  if (a > b) {tmp = a; a = b; b = tmp;}  /* a <= b */
  if (a > c) {tmp = a; a = c; c = tmp;}  /* a <=c && a <= b */
  if (b > c) {tmp = b; b = c; c = tmp;}  /* b <= c */
  printf("%d %d %d\n", a, b, c);

  return 0;
}

