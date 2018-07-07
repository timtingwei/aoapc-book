// copyright [2018] <mituh>
// 1, strchr(s, c) == NULL 查找字符串s中是否有字符c
// 2, scanf(%s, a) 读入a是字符数组, 不用&读取字符串
// 3, sprintf输出到字符串, 不过要主要数组大小
// 4, strlen获取字符串长度, 也可以获取字符数组的长度

#include <stdio.h>
#include <string.h>
char a[20], buf[99];
int main() {
  int cnt = 0;
  scanf("%s", a);
  for (int abc = 100; abc <= 999; abc++) {
    for (int de = 10; de <= 99; de++) {
      int x = abc * (de%10), y = abc * (de/10), z = x + y*10;
      sprintf(buf, "%d%d%d%d%d", abc, de, x, y, z);
      int ok = 1;
      for (int i = 0; i < strlen(buf); i++) {
        if (strchr(a, buf[i]) == NULL) {ok = 0; break;}
      }
      if (ok) {
        printf("<%d>\n%5d\nX%4d\n-----\n%5d\n%4d\n-----\n%5d\n\n",
               ++cnt, abc, de, x, y, z);
      }
    }
  }
  printf("The number of solution = %d\n", cnt);

  printf("%lu %lu\n", strlen(a), strlen("tim"));

  return 0;
}
