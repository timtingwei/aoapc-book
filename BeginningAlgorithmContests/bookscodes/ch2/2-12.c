#include <stdio.h>
#define INF 1000000000

int main() {
  FILE *fin, *fout;
  fin = fopen("input.in", "rb");
  fout = fopen("output.out", "wb");
  int n, max = -INF, min = INF, sum = 0, cnt = 0,
      case_n = 0, case_i = 0, case_cnt = 0;
  while (fscanf(fin, "%d", &n) == 1) {
    if (case_i == 0) {
      if (n == 0) {
        break;
      }
      case_n = n;
      case_i++;
      continue;
    }

    if (case_i > case_n) {
      printf("Case %d : %d %d %.3f\n\n", case_cnt, min, max, (double)sum / cnt);
      case_cnt++;
      case_n = n;
      case_i = 1;
      max = -INF, min = INF, sum = 0, cnt = 0;
      continue;
    }
    // else

    if (max < n) {max = n;}
    if (n < min) {min = n;}
    sum += n;
// /*
    printf("%d %d %d\n", min, max, sum);
// */
    cnt++;
    case_i++;
  }

  fclose(fin);
  fclose(fout);

  return 0;
}
