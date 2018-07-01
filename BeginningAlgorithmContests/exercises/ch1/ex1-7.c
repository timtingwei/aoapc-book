// copyright [2018] <mituh>
// year
#include <stdio.h>
int main() {
  int y;
  scanf("%d", &y);
  if (((y % 4 == 0) && (y % 100 != 0)) || ((y % 400 == 0) && (y % 3200 != 0))) {
    printf("%s\n", "yes");
  } else {
    printf("%s\n", "no");
  }

  return 0;
}
