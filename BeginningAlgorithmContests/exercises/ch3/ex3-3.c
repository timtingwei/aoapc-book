// copyright [2018] <mituh>
// Digit Counting, UVa1225(数数字)


#include <stdio.h>
#define MAXN 1000000 + 10
char s[MAXN];

int foo() {
  int n, cnt = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int t = i;
    while (t > 0) {
      s[cnt++] = '0' + t % 10;
      t /= 10;
    }
  }

  for (int i = 0; i <= 9; i++) {
    int cnt_i = 0;
    for (int j = 0; j < cnt; j++) {
      if (s[j] - '0' == i) { cnt_i++; }
    }
    (i == 9) ? printf("%d\n", cnt_i) : printf("%d ", cnt_i);
  }

  return 0;
}

int main() {
  int T;
  if (scanf("%d", &T) == 1 && (T <= 20)) {
    while (T--) {
      foo();
    }
  }

  return 0;
}
