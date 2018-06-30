#include <stdio.h>
#include <math.h>
int main() {
  int a;
  scanf("%d", &a);
  int b = a/100 + a/10%10*10 + a%10*100;
  printf("%03d\n", b);

  return 0;
}
