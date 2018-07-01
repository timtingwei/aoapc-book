#include <stdio.h>
#include <math.h>
int main() {
  unsigned int n;
  scanf("%u", &n);
  if (n <= 0 || 360 <= n) return -1;
  printf("%f %f\n", sin(n), cos(n));

  return 0;
}
