#include <stdio.h>
int main() {
  const int INF = 2000000000;
  int n, max = -INF, min = INF, sum = 0, cnt = 0;
  while (scanf("%d", &n) == 1) {
    if (max < n) {max = n;}
    if (n < min) {min = n;}
    sum += n;
    cnt++;
  }
  printf("%d %d %.3f\n", min, max, (double)sum / cnt);

  return 0;
}
