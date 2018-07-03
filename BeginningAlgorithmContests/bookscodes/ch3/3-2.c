#include <stdio.h>
#include <string.h>
#define MAXN 10000
int arr[MAXN];
int main() {
  int n, k, first = 1;
  scanf("%d%d", &n, &k);
  memset(arr, 0, sizeof(arr));         // off
  for (int i = 1; i <= k; i++) {
    for (int j = 1; j <= n; j++) {
      arr[j*i] = !arr[j*i];            // change toggle
    }
  }
  for (int i = 1; i <= n; i++) {
    if (arr[i]) { if (first) first = 0; else printf(" "); printf("%d", i); }
  }
  printf("\n");

  return 0;
}
