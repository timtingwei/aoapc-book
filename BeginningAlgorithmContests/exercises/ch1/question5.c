// copyright [2018] <mituh>
#include <stdio.h>
int main() {
  int a = 0, b = 1;
  int x = 0, y = 0;
  // if (a) if (b) x++; else y++;

  if (a) {
    if (b) {
      x++;
    } else {
      y++;
    }
  }

  /*
  if (a) {
    if (b)
      x++;
  } else {
    y++;
  }
  */
  printf("%d %d\n", x, y);

  return 0;
}
