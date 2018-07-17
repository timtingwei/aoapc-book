// copyright [2018] <mituh>
// Score, UVa1585

#include <stdio.h>
#include <string.h>
char s[85];

int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("b.out", "w", stdout);
#endif
  int T;
  scanf("%d", &T);
  while (T--) {
    int x = 0, sum = 0;
    scanf("%s", s);
    for (int i = 0; i < strlen(s); i++) {
      if (s[i] == 'O') {
        x++;
      } else {
        x = 0;
      }
      // printf("%d ", x);
      sum += x;
    }
    printf("%d\n", sum);
  }

  return 0;
}
