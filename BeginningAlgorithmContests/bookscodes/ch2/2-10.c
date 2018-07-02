#define LOCAL
#include <stdio.h>
#define INF 1000000000

int main() {
#ifdef LOCAL
  freopen("input.in", "r", stdin);
  freopen("output.out", "w", stdout);
#endif
  // const int INF = 1000000000;
  int n, max = -INF, min = INF, sum = 0, cnt = 0;
  while (scanf("%d", &n) == 1) {
    if (max < n) {max = n;}
    if (n < min) {min = n;}
    sum += n;
/*
    printf("%d %d %d\n", min, max, sum);
*/
    cnt++;
  }
  printf("%d %d %.3f\n", min, max, (double)sum / cnt);

  return 0;
}
