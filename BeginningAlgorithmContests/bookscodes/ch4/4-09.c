// copyright [2018] <mituh>
// 4-9 另外两种计算数组元素和写法(正确)

#include <stdio.h>
/*
int sum(int* a, int n) {  // 在函数调用时, 不一定只传入数组, 还可以传入地址
  int ans = 0;
  for (int i = 0; i < n; i++)
    ans += a[i];
  return ans;
}
*/

int sum(int* begin, int* end) {  // 把begin当作数组, 用下标累加
  int ans = 0;
  int n = end - begin;
  for (int i = 0; i < n; i++)
    ans += begin[i];
  return ans;
}


/*
int sum(int* begin, int* end) {  // 把begin当作地址, 解引用指针迭代器累加
  int ans = 0;
  for (int* it = begin; it != end; it++)
    ans += *it;
  return ans;
}
*/

int main() {
  // ..
  int n = 4;
  int a[] = {1, 2, 3, 4};
  // printf("%d\n", sum(a + 1, 3));
  printf("%d\n", sum(a, a + 4));
  return 0;
}
