#include <stdio.h>
int main() {
  int n = 2;
  double v = 1.0 / 3.0, sum = 1.0;
  do {
    
    if (n % 2) {  // odd
      sum += v;
    } else {  // even
      sum -= v;
    }
    n++;
  }
  while ((v = 1.0 / (2 * n - 1)) >= 10e-6);

  printf("%f\n", sum);
  return 0;
}
