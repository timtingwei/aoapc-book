#include <stdio.h>
int main() {
  double sum = 0, v;
  for (int i = 0; ; i++) {
    double v = 1.0 / (2 * i + 1);
    sum = (i % 2) ? sum - v : sum + v;
    if (v < 1e-6) break;
  }

  printf("%.6f\n", sum);
  return 0;
}
