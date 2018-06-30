#include <stdio.h>
#include <math.h>
int main() {
  int a;
  scanf("%d", &a);
  printf("%d%d%d\n", a%10, a/10%10, a/100);

  return 0;
}
