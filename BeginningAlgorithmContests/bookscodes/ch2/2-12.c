#include <stdio.h>
#define INF 1000000000

int main() {
  FILE *fin, *fout;
  fin = fopen("input.in", "rb");
  fout = fopen("output.out", "wb");
  int n, x, kase = 0;


  while (fscanf(fin, "%d", &n) == 1 && n) {
    int sum = 0, max = -INF, min = INF;
    for (int i = 0; i < n; i++) {  // loop n count
      fscanf(fin, "%d", &x);
      if (max < x) {max = x;}
      if (x < min) {min = x;}
      sum += x;
    }
    if (kase) fprintf(fout, "\n");
    fprintf(fout, "Case %d : %d %d %.3f\n", kase++, min, max, (double)sum / n);
    /*
    if (is_line) {
      if (n == 0) {
        break;
      } else {
        case_n = n;
        max = -INF, min = INF, sum = 0, cnt = 0;
        is_line = 0;  // next value is valid value
      }
    } else {
      if (max < n) {max = n;}
      if (n < min) {min = n;}
      sum += n;
      cnt++;
      if (cnt == case_n) {
        fprintf(fout, "Case %d : %d %d %.3f\n\n", case_cnt, min, max, (double)sum / cnt);
        is_line = 1;
        case_cnt++;
      }
    }
    */
    /*
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

    // printf("%d %d %d\n", min, max, sum);

    cnt++;
    case_i++;
    */
  }

  fclose(fin);
  fclose(fout);

  return 0;
}
