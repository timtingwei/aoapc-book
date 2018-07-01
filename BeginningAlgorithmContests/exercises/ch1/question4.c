// copyright [2018] <mituh>
#include <stdio.h>
int main() {
  int a, b, c;
  a = 0, b = 0, c = 1;
  int r = (a && b) || c;

  printf("%d\n", r);
  return 0;
}

/*
  question4.c:6:13: warning: '&&' within '||' [-Wlogical-op-parentheses]
  int r = a && b || c;
          ~~^~~~ ~~
  question4.c:6:13: note: place parentheses around the '&&' expression to silence this warning
  int r = a && b || c;
            ^
          (     )


我的gcc提示我要把它括进括号里@_@.
也许是怎么理解都可以吧, 所以写的时候还是明确的定义.
 */
