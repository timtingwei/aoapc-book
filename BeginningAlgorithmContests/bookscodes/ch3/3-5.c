// copyright [2018] <mituh>

#include <stdio.h>
char a[1000];
int main() {
  FILE *fin, *fout;
  fin = fopen("input.in", "rb");
  fout = fopen("output.out", "wb");

  // char c;
  int q = 1;
  int c;

  while ((c = getchar()) != EOF) {
    if (c == '"') { printf("%s", q ? "``" : "''"); q = !q;}
    else printf("%c", c);
  }

  fclose(fin);
  fclose(fout);
  return 0;
}

