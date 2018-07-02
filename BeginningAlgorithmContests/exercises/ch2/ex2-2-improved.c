#include <stdio.h>
int main() {
  FILE *fin, *fout;
  fin = fopen("input.in", "rb");
  fout = fopen("output.out", "wb");
  int a, b, c, n = 0, case_n = 1;
  while ((fscanf(fin, "%d%d%d", &a, &b, &c) == 3) && (a < 3 && b < 5 && c < 7)) {
    if (n == 3) {
      n = 0;
    }
    int i = 70 * a + 21 * b + 15 * c;
    i = (i <= 105) ? i : i % 105;
    if (10 <= i && i <= 100) {
      fprintf(fout, "Case %d: %d\n", case_n++, i);
    } else {
      fprintf(fout, "Case %d: No answer\n", case_n++);
    }
    n++;
  }
  fclose(fin);
  fclose(fout);


  return 0;
}

