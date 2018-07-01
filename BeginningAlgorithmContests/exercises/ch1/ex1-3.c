#include <stdio.h>
int main() {
  int n, r;
  scanf("%u", &n);
  if (n < 0) return -1;
  r = (1+n)*n/2;
  printf("%ld\n", r);

  return 0;
}
