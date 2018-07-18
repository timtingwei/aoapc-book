// copyright [2018] <mituh>
// 227 - Puzzle(谜题)
/*

TRGSJ
XDOKI
M VLN
WPABE
UQHCF
ARRBBL0

 012345
0
1 TRGSJ
2 XDOKI
3 M VLN
4 WPABE
5 UQHCF
pos[0] = 3, pos[1] = 2

ABCDE
FGHIJ
KLMNO
PQRS
TUVWX
AAA
LLLL0

Puzzle #3:
T R G S J
X O K L I
M D V B N
W P   A E
U Q H C F

*/
#include <stdio.h>
#include <string.h>
#define MAXN 5 + 5
#define MAXM 20 + 5
char a[MAXN][MAXN];
char m[MAXM];

void swap_c(char *ca_p, char *cb_p) {
  char ct;
  ct = *ca_p; *ca_p = *cb_p; *cb_p = ct;
}

void watch_msg(char (*a)[MAXN], const int *pos) {
  for (int i = 1; i <= 5; i++) {
    for (int j = 1; j <= 5; j++) {
      (j == 5) ? printf("%c", a[i][j]) : printf("%c ", a[i][j]);
    }
    printf("\n");
  }
}

int foo(int* kase, int* find_z) {
  // 将二维数组设置成全空字符
  memset(a, ' ', sizeof(a));
  int c, j = 0;
  int pos[2];
  while ((c = getchar()) != EOF) {
    // 如果首个字符为Z, 找到z, 返回该函数
    if (c == 'Z') {*find_z = 1; return 0;}
    if (c == '\n') continue;
    if (c == ' ') { pos[0] = j / 5 + 1, pos[1] = j % 5 + 1; }  // 提前右移
    a[j/5+1][j%5] = c;
    // printf("%c %d %d\n", c, j/5 + 1, j%5);
    j++;
    // 读取完格子阵列, 退出循环
    if (j == 25) break;
  }
  // printf("\n");
  // printf("j = %d\n", j);

  for (int i = 1; i <= 5; i++) {
    for (int j = 5; j > 0; j--) {
      // 向右边移动一位
      a[i][j] = a[i][j-1];
    }
    // 每行首部为空字符
    a[i][0] = ' ';
  }

  int ok = 1;
  while ((c = getchar()) != '0') {
    if (c == '\n') continue;
    char ct;  // 用于交换的临时字符变量
    if (c == 'L') {
      // ..
      if ((pos[1] - 1) == 0) {
        ok = 0;
        continue;   // 为了最终读到字符'0'做出的牺牲
      }
      ct = a[pos[0]][pos[1]-1];
      a[pos[0]][pos[1]-1] = ' ';
      a[pos[0]][pos[1]] = ct;
      // swap_c(&a[pos[0]][pos[1]-1], &a[pos[0]][pos[1]]);
      pos[1]--;
    } else if (c == 'R') {
      // ..
      if (pos[1] + 1 == 6) {
        ok = 0;
        continue;
      }
      ct = a[pos[0]][pos[1]+1];
      a[pos[0]][pos[1]+1] = ' ';
      a[pos[0]][pos[1]] = ct;
      pos[1]++;
    } else if (c == 'A') {
      // ..
      if (pos[0] - 1 == 0) {
        ok = 0;
        continue;
      }
      ct = a[pos[0]-1][pos[1]];
      a[pos[0]-1][pos[1]] = ' ';
      a[pos[0]][pos[1]] = ct;
      pos[0]--;
    } else if (c == 'B') {
      // ..
      if (pos[0] + 1 == 6) {
        ok = 0;
        continue;
      }
      ct = a[pos[0]+1][pos[1]];
      a[pos[0]+1][pos[1]] = ' ';
      a[pos[0]][pos[1]] = ct;
      pos[0]++;
    } else {
      return -1;
    }
    // watch_msg(a, pos);
  }
  printf("Puzzle #%d:\n", ++(*kase));
  if (ok) {
    watch_msg(a, pos);
  } else {
    printf("This puzzle has no final configuration.\n");
  }
  return 0;
}

int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("b.out", "w", stdout);
#endif
  int kase = 0, find_z = 0;
  for (;;) {
    // 在foo内部修改kase计数, 一旦getchar('Z'), 返回函数, 且终止循环.
    foo(&kase, &find_z);
    if (find_z) {
      break;
    } else {
      printf("\n");
    }
  }

  return 0;
}

/*
 BCDE
FGHIJ
KLMNO
PQRSY
TUVWX
L0
ABCD 
FGHIJ
KLMNO
PQRSY
TUVWX
R0
TRGSJ
XDOKI
M VLN
WPABE
UQHCF
AR
RB
BL0
 BCDE
FGHIJ
KLMNO
PQRSY
TUVWX
A0
ABCDE
FGHIJ
KLMNO
PQRSY
T VWX
B0
TRGSJ
XDOKI
M VLN
WPABE
UQHCF
ARRBBLQ0
Z

Puzzle #1:
This puzzle has no final configuration.

Puzzle #2:
This puzzle has no final configuration.

Puzzle #3:
T R G S J
X O K L I
M D V B N
W P   A E
U Q H C F

Puzzle #4:
This puzzle has no final configuration.

Puzzle #5:
This puzzle has no final configuration.

Puzzle #6:
This puzzle has no final configuration.

*/
