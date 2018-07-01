#include <stdio.h>
int main() {
  unsigned int n;
  double account;
  scanf("%d", &n);
  account = (n*95) >= 300 ? n*95*0.85 : n*95;
  printf("%.2f\n", account);

  return 0;
}
