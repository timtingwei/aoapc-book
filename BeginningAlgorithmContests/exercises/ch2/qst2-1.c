// copyright [2018] <mituh>

#include <stdio.h>
/*
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    printf("%d\n", i*2);
  }

  return 0;
}
*/

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 2; i <= 2*n; i += 2) {
    printf("%d\n", i);
  }

  return 0;
}
