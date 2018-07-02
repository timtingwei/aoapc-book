
#include <stdio.h>
#define INF 1000000000

int main() {
  // freopen("input.in", "r", stdin);
  // freopen("output.out", "w", stdout);
  FILE *fin, *fout;
  fin = fopen("input.in", "rb");
  fout = fopen("output.out", "wb");

  int n, max = -INF, min = INF, sum = 0, cnt = 0;
  while (fscanf(fin, "%d", &n) == 1) {
    if (max < n) {max = n;}
    if (n < min) {min = n;}
    sum += n;
/*
    printf("%d %d %d\n", min, max, sum);
*/
    cnt++;
  }
  fprintf(fout, "%d %d %.3f\n", min, max, (double)sum / cnt);
  fclose(fin);
  fclose(fout);

  return 0;
}
