// copyright [2018] <mituh>
// Master-Mind Hints, UVa 340
/*
  给定答案序列和用户猜的序列, 统计有多少数字位置正确(A), 有多少数字在两个序列都出现过但位置不对(B)
  输入包含多组数据, 每组输入第一行为序列长度n, 第二行是答案序列, 接下来是若干猜测序列. 猜测序列全0时该组数据结束. n=0时输入结束.
*/

#include <stdio.h>
#define MAXN 1000

void print_arr(int* arr, int n) {
  printf("arr = ");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main() {
  int n, tmp, cnt = 0;
  while ((scanf("%d", &n) == 1) && n) {
    // each Game
    int a[MAXN], b[MAXN];
    // write answer to array a
    for (int i = 0; i < n; i++) {
      if (scanf("%d", &tmp) == 1) { a[i] = tmp;}
    }
    printf("Game %d:\n", cnt);

    // write guess the answer to array b
    int ok = 1;
    while (ok) {
      int all_zero = 1, A = 0, B = 0;
      int a_use[MAXN] = {};
      for (int i = 0; i < n; i++) {
        if (scanf("%d", &tmp) == 1) {
          b[i] = tmp;
          // /*
          if (a[i] == tmp) {
            a_use[i] = 1;
            A++;
          } else {
            a_use[i] = 0;
          }
          all_zero = (tmp != 0) ? 0 : all_zero;
        }
      }
      // is it a guess not all zero ?
      if (all_zero) { ok = !ok; cnt++; break;}

      // judge the A and B, put out hint
      for (int y = 0; y < n; y++) {    // 猜测数组 b 的位置
        int ti = 0;
        while (ti < n) {
          if (a_use[ti]) {
            ti++;
          } else {  // ti对应数字未被使用过
            if (b[y] == a[ti]) {
              a_use[ti] = 1;
              B++;
              break;
            } else { ti++;}
          }
        }
      }
      printf("(%d,%d)\n", A, B);
    }
  }

  return 0;
}
