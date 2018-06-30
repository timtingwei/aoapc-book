#include <stdio.h>
/* my test use loop
int main() {
  int n, m, a, b;
  scanf("%d%d", &n, &m);
  for (a = 0; a <= n; a++) {
    b = n - a;
    if ((2*a+4*b) == m) {
      printf("%d %d\n", a, b);
      return 0;
    }
  }
  printf("No answer\n");
  return -1;
}
*/

int main() {
  int n, m, a, b;
  scanf("%d%d", &n, &m);
  a = (4*n-m)/2;
  b = n - a;
  if (m % 2 == 1 || a < 0 || b < 0) {
    printf("No answer\n");
  } else {
    printf("%d %d\n", a, b);
  }

  return 0;
}
