// copyright [2017] <mituh>
// triangle
#include <stdio.h>
#include <math.h>
int main() {
  int a, b, c, t;
  scanf("%d %d %d", &a, &b, &c);
  if (a <= 0 || b <= 0 || c <= 0) return -1;
  if (a > b) {t = a; a = b; b = t;}  /* a <= b */
  if (a > c) {t = a; a = c; c = t;}  /* a <= c */
  if (b > c) {t = b; b = c; c = t;}  /* b <= c */
  if (a + b <= c || a <= c - b) {
    printf("%s\n", "not a triangle");
  } else {  /* is a triangle */
    if (a*a + b*b == c*c) {
      printf("%s\n", "yes");
    } else {
      printf("%s\n", "no");
    }
  }

  return 0;
}
