// copyright [2018] <mituh>
// UVa 521 Spreadsheet Tracking 追踪电子表格中的单元格
/*
input:
7 9
11 12 13 14 15 16 17 18 19
21 22 23 24 25 26 27 28 29
31 32 33 34 35 36 37 38 39
41 42 43 44 45 46 47 48 49
51 52 53 54 55 56 57 58 59
61 62 63 64 65 66 67 68 69
71 72 73 74 75 76 77 78 79
*/
#include <stdio.h>
#include <string.h>   // use memset
#define MAXN 50
int a[MAXN][MAXN];
int r, c;
int ip[MAXN][MAXN];   // 当前表中数据在原表格中索引, 用两位数表示
int R, C;
int cvt_ip[MAXN][MAXN];
/*
11 12 13 14 15 16 17 18 19
21 22 23 24 25 26 27 28 29
31 32 33 34 35 36 37 38 39
41 42 43 44 45 46 47 48 49
51 52 53 54 55 56 57 58 59
61 62 63 64 65 66 67 68 69
71 72 73 74 75 76 77 78 79
*/

void printtable() {
  printf("table:\n");
  for (int j = 0; j <= c; j++) printf("%4d", j);
  printf("\n");
  for (int i = 1; i <= r; i++) {
    printf("%4d", i);
    for (int j = 1; j <= c; j++) {
      printf("%4d", a[i][j]);
    }
    printf("\n");
  }
}
void printindex() {
  printf("index:\n");
  for (int j = 0; j <= C; j++) printf("%d  ", j);
  printf("\n");
  for (int i = 1; i <= R; i++) {
    printf("%d ", i);
    for (int j = 1; j <= C; j++) {
      printf("%d ", ip[i][j]);
    }
    printf("\n");
  }
}

void readtable() {
  for (int i = 1; i <= r; i++) {
    for (int j = 1; j <= c; j++) {
      scanf("%d", &a[i][j]);
      ip[i][j] = i*10 + j;
    }
  }
}

void exchange(int r1, int c1, int r2, int c2) {
  // 交换该位置对应值, 交换该位置目前存放的原表位置
  if (r1 > r || c1 > c || r2 > r || c2 > c) {
    printf("exchange error!\n"); return;
  }
  int t = a[r1][c1]; a[r1][c1] = a[r2][c2]; a[r2][c2] = t;
  t = ip[r1][c1]; ip[r1][c1] = ip[r2][c2]; ip[r2][c2] = t;
}

void remove_r(int n) {
  // 删除单行, 改变表中数据, 改变原表位置对应的新索引
  if (n > r) {printf("remove_r error!\n"); return;}
  for (int i = n; i <= r-1; i++) {
    for (int j = 1; j <= c; j++) {
      exchange(i, j, i+1, j);
    }
  }
  r--;
  printf("remove %d row, r=%d\n", n, r);
}

void remove_c(int n) {
  // 删除单列, 改变表中数据, 改变原表位置对应的新索引
  if (n > c) {printf("remove_c error!\n"); return;}
  for (int j = n; j <= c-1; j++) {
    for (int i = 1; i <= r; i++) {
      exchange(i, j, i, j+1);
    }
  }
  c--;
  printf("remove %d column, c=%d\n", n, c);
}

void insert_r(int n) {
  // 插入单行
  if (n > r) {printf("insert_r error!\n"); return;}
  // for (int j = c+1; 1 <= j; j--) a[i][] 
  for (int i = n+1; i <= r-1; i++) {
    for (int j = 1; j <= c; j++) {
      exchange(i, j, i+1, j);
    }
  }
  r--;
  printf("remove %d row, r=%d\n", n, r);
}

void insert_c(int n) {
  // 插入单列
  if (n > c) {printf("insert_r error!\n"); return;}
  C++;  // 总体新增一列
  for (int i = 1; i <= R; i++) {
    a[i][C] = 0; ip[i][C] = i*10+C;  // 数值为0, 索引为当前格子
  }
  for (int j = C; j >= n; j--) {
    for (int i = 0; i <= r; i++) {
      exchange(i, j-1, i, j);
    }
  }
  c++;  // 表的有效部分新增1
}


void remove_multi() {
  // 删除多行1, 5
}
/*
删除1, 5行 => 删除第1行, 删除第4行.
删除1, 3, 7; => 删除1, 2, 6;
11 12 13 14 15 16 17 18 19 
21 22 23 24 25 26 27 28 29 -> 31 32 33 34 35 36 37 38 39  r
31 32 33 34 35 36 37 38 39 -> 
41 42 43 44 45 46 47 48 49 
51 52 53 54 55 56 57 58 59 
61 62 63 64 65 66 67 68 69 
71 72 73 74 75 76 77 78 79
*/

void convert_index() {
  // 将索引与数值反转, 方便于查询功能
  memset(cvt_ip, 0, sizeof(cvt_ip));
  for (int i = 1; i <= R; i++) {
    for (int j = 1; j <= C; j++) {
      int x = ip[i][j] / 10 % 10;
      int y = (ip[i][j]) % 10;
      cvt_ip[x][y] = i*10+j;    // 原始(x, y)-> 对应新位置是(i, j)
// printf("cvt_ip[%d][%d] = %d\n", x, y, cvt_ip[x][y]);
    }
  }
}

void find(int r, int c) {
  int x = cvt_ip[r][c] / 10 % 10;
  int y = cvt_ip[r][c] % 10;
  if (x > r || y > c) {  printf("find:is deleted\n");
  } else {
    printf("find: r = %d, c = %d\n", cvt_ip[r][c] / 10 % 10, cvt_ip[r][c] % 10);
  }
}

int main() {
  if (scanf("%d%d", &r, &c) == 2 && r && c) {
    R = r, C = c;
    readtable();
  } else {return -1;}
  printtable();
  // exchange(3, 4, 2, 2);
  // printtable();
  /*
  remove_r(2);
  printtable();
  printindex();
  remove_c(3);
  printtable();
  printindex();
  remove_c(4);
  printtable();
  printindex();
  */


  // remove_c(2);
  
  insert_c(2);
  printtable();
  printindex();


  convert_index();
  find(4, 2);
  return 0;
}
