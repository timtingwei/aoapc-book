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
    int is_find = 0;
    for (int i = 10; i <= 100; i++) {
      if ((i % 3 == a) && (i % 5 == b) && (i % 7 == c)) {
        fprintf(fout, "Case %d: %d\n", case_n++, i);
        is_find = 1;
        break;
      }
    }
    if (!is_find) fprintf(fout, "Case %d: No answer\n", case_n++);
    n++;
  }
  fclose(fin);
  fclose(fout);


  return 0;
}
