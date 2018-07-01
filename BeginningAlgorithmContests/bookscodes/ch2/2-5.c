#include <stdio.h>
int main() {
  int n, cnt = 0;
  scanf("%d", &n);
  long long n2 = n;
  if (n2 > 10e9 || n2 <= 1) return -1;
  while (n2 != 1) {
    if (n2 % 2) {
      n2 = 3 * n2 + 1;
    } else {
      n2 /= 2;
    }
    cnt++;
  }
  printf("%d\n", cnt);

  return 0;
}
