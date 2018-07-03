// copyright [2018] <mituh>
// int to double precision
// test redirection I/O

#include <stdio.h>
int main() {
  /*
#ifdef LOCAL
  freopen("input.in", "r", stdin);
  freopen("output.out", "w", stdout);
#endif
  */
  FILE *fin, *fout;
  fin = fopen("input.in", "rb");
  fout = fopen("output.out", "wb");
  int n;
  fscanf(fin, "%d", &n);
  double i;
  for (i = 0; !(n - i < 0.0001); i += 0.1) {
    fprintf(fout, "%.1f\n", i);
  }
  fclose(fin);
  fclose(fout);

  return 0;
}
