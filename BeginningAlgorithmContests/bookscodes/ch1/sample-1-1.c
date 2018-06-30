#include <stdio.h>
#include <math.h>
/* error..
int main() {
  float r, h;
  printf("input r and h:\n");
  scanf("%f%f", &r, &h);
  float area = 3.14159 * pow(r, 2) * h;
  printf("area = %f\n", area);

  return 0;
}
*/

int main() {
  const float PI = acos(-1.0);
  float r, h, s1, s2, s;
  scanf("%1f%1f", &r, &h);
  s1 = PI * r * r;
  s2 = 2 * PI * r * h;
  s = 2 * s1 + s2;
  printf("Area = %.3f\n", s);

  return 0;
}
