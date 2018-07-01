#include <stdio.h>
int main () {
  int n, cnt = 0;
  scanf("%d", &n);
  if (n > 10e9 || n <= 1) return -1;
  while (n != 1) {
    if (n % 2) {
      n = 3 * n + 1;
    } else {
      n /= 2;
    }
    cnt++;
  }
  printf("%d\n", cnt);

  return 0;
}
