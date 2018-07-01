#include <stdio.h>
#include <math.h>
/* my test
int main() {
  for (int a = 1; a <= 9; a++) {
    for (int b = 0; b <= 9; b++) {
      int v = a * 1100 + b * 11;
      int s = sqrt(v);
      if ((sqrt(v) - s) == 0.0)
        printf("%d\n", v);
    }
  }

  return 0;
}
*/

int main() {
  for (int a = 1; a <= 9; a++) {
    for (int b = 0; b <= 9; b++) {
      int v = a * 1100 + b * 11;
      int s = floor(sqrt(v) + 0.5);
      if (s * s == v)
        printf("%d\n", v);
    }
  }

  return 0;
}
