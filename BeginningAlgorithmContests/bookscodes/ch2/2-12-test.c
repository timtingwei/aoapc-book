#include <stdio.h>
#define INF 1000000000

int main() {
  FILE *fin, *fout;
  fin = fopen("input.in", "rb");
  fout = fopen("output.out", "wb");
  int n, max = -INF, min = INF, sum = 0, cnt = 0,
      case_n = 0, case_cnt = 0;
  // int case_i = 0;
  int is_line = 1;
  while (fscanf(fin, "%d", &n) == 1) {
    /* 当前整数代表为个数 */
    //   若行号整数为0, break
    //   否则
    //     设置接下来的整数个数case_n
    //     初始化每次计算三个值所用到变量
    //     标记下一行为有效数值
    /* 当前整数为有效数值 */
    //   改变max, min, sum, cnt,
    //   若计数为case_n,
    //     打印Case信息,
    //     标记下一行为行号

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
