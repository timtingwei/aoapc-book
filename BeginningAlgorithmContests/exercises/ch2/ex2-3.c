#include <stdio.h>
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    // print space
    for (int t = 0; t < i; t++) printf("%s", " ");
    // print asterisk *
    for (int j = 0; j < 2 * (n-i)-1; j++) {
      printf("%s", "*");
    }
    // print enter
    printf("\n");
  }

  return 0;
}
