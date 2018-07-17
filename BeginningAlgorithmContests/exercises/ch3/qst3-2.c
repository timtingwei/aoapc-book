// copyright [2018] <mituh>
/*
  统计字符串中字符1的个数, 一个导致无法运行, 一个结果不正确, 还有一个效率低下
 */

/*
#include <stdio.h>
#define MAXN 10000000 + 10                // 无法运行X, => 实际可以运行
int main() {
  char s[MAXN];
  scanf("%s", s);
  int tot = 0;
  for (int i = 0; i < strlen(s); i++)     // 效率低下X  => 无法运行
    if (s[i] == 1) tot++;                 // 结果不正确
  printf("%d\n", tot);

  return 0;
}
*/

#include <stdio.h>
#include <string.h>
#define MAXN 1000000 + 10
char s[MAXN];
int main() {
  // char s[MAXN];                       // 数组定义在内部, 效率低下
  scanf("%s", s);
  int tot = 0;
  for (int i = 0; i < strlen(s); i++)     // 效率低下X  -> 无法运行
    if (s[i] == '1') tot++;               // 结果不正确
  printf("%d\n", tot);

  return 0;
}

/*
无法运行: strlen()函数定义在string.h头文件中
效率低下: 数组定义在外部, 数组大小可以定义的稍大, 在main函数内, 数组稍大就会异常(Segmentation fault: 11)退出
结果错误: 字符与'1'比等, 而不是与整型1
*/
