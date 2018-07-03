#include <stdio.h>
#include <string.h>
#define MAXN 105
int arr[MAXN];
int main() {
  int n, cnt = 0;
  while (scanf("%d", &n) == 1) {
    arr[cnt++] = n;
  }
  for (int i = cnt - 1; i >= 1; i--) {
    printf("%d ", arr[i]);
  }
  printf("%d\n", arr[0]);

  return 0;
}
