// copyright [2018] <mituh>

#include <stdio.h>
#include <ctype.h>

#define MAX_INT 2147483647
#define MIN_INT -2147483648

int foo1() {
  // 统计一些数, 统计个数.   => 不用数组
  int a, cnt = 0;
  while (scanf("%d", &a) == 1) {
    cnt++;
  }
  printf("%d\n", cnt);
  return 0;
}

int foo2() {
  // 输入一些数, 求最大值, 最小值, 平均数  => 不用数组
  int a, min = MAX_INT, max = MIN_INT, sum = 0, cnt = 0;
  while (scanf("%d", &a) == 1) {
    if (max < a) max = a;
    if (a < min) min = a;
    sum += a;
    cnt++;
  }
  printf("%d %d %.3f\n", max, min, (sum+0.0001)/cnt);

  return 0;
}

int foo3() {
  // 输入一些数, 哪两个数最接近  => 用数组
  int a[105], b, n = 0;
  while (scanf("%d", &b) == 1) { a[n++] = b; }
  
  int min_pos = 1, min = MAX_INT;
  for (int i = 1; i < n; i++) {
    int mi = (a[i-1] < a[i]) ? a[i] - a[i-1] : a[i-1] - a[i];
    printf("mi = %d\n", mi);
    if (mi < min) { min = mi; min_pos = i;}
  }
  printf("%d %d\n", a[min_pos - 1], a[min_pos]);


  return 0;
}

int main() {
  // foo1();
  // foo2();
  foo3();

  return 0;
}
