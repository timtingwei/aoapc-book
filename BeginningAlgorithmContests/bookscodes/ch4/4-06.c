// copyright [2018] <mituh>
// 4-06 用函数交换变量(用函数交换变量)

#include <stdio.h>
void swap(int* a, int* b) {
  int tmp = *a; *a = *b; *b = tmp
}

int main() {
  int a = 3, b = 4;
  swap(&a, &b);
  printf("%d %d\n", a, b);

  return 0;
}
