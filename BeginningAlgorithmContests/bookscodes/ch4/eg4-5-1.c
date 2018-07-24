// copyright [2018] <mituh>
// UVa 521 Spreadsheet Tracking 追踪电子表格中的单元格
/*
  思路: 对需要查询的数据进行计算
  先写框架, 后写细节

intput:
7 9
5
DR 2 1 5
DC 4 3 6 7 9
IC 1 3
IR 2 2 4
EX 1 2 6 5
4
4 8
5 5
7 8
6 5
output:
Spreadsheet #1
Cell data in (4,8) moved to (4,6)
Cell data in (5,5) GONE
Cell data in (7,8) moved to (7,6)
Cell data in (6,5) moved to (1,2)
*/

#include <stdio.h>
#include <string.h>
char cmd[3];
int alg[50];  // 50操作次数
int a_para[50][50];
int para_n[50];
int is_gone;

void del_r(int* para, int n, int* r, int* c) {
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (para[i] == (*r)) {is_gone = 1; return;}
    if (para[i] < (*r)) cnt++;
  }
  (*r) -= cnt;
}
void del_c(int* para, int n, int* r, int* c) {
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (para[i] == (*c)) {is_gone = 1; return;}
    if (para[i] < (*c)) cnt++;
  }
  (*c) -= cnt;
}

void ins_r(int* para, int n, int* r, int* c) {
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (para[i] <= (*r)) cnt++;
  }
  (*r) += cnt;
}
void ins_c(int* para, int n, int* r, int* c) {
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (para[i] <= (*c)) cnt++;
  }
  (*c) += cnt;
}
void exc(int* para, int n, int* r, int* c) {
  if ((para[0] == (*r) && para[1] == (*c)) ||
      (para[2] == (*r) && para[3] == (*c))) {
    if (para[0] == (*r)) {
      *r = para[2], *c = para[3];
    } else {
      *r = para[0], *c = para[1];
    }
  }
}


int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("b.in", "w", stdout);
#endif
  int r, c, rr, cc, n, n2, kase = 0;
  while (scanf("%d %d", &r, &c) == 2) {
    (++kase == 1) ? printf("Spreadsheet #%d\n", kase)
        : printf("\nSpreadsheet #%d\n", kase);
// int alg_cnt = 0;
    scanf("%d", &n);
    memset(para_n, 0, sizeof(para_n));
    memset(a_para, 0, sizeof(a_para));
    for (int i =0; i < n; i++) {
// printf("i=%d\n", i);
// printf("alg_cnt=%d\n", i);
      memset(cmd, 0, sizeof(cmd));
      scanf("%s", cmd);
      if (cmd[0] == 'E') {
        // EX 1 2 6 5
        para_n[i] = 4;
        for (int nj = 0; nj < 4; nj++) scanf("%d", &a_para[i][nj]);
        alg[i] = 4;                            // EX 4
      } else {
        // DR X a b c d
        int nn;
        scanf("%d", &nn);
// printf("nn=%d\n", nn);
        para_n[i] = nn;
// printf("para_n[%d]=%d\n", i, para_n[i]);
        for (int nj = 0; nj < nn; nj++) {
          scanf("%d", &a_para[i][nj]);
        }
        if (cmd[0] == 'D') {
          if (cmd[1] == 'R') alg[i] = 0;       // DR 0
          else if (cmd[1] == 'C') alg[i] = 1;  // DC 1
        } else if (cmd[0] == 'I') {
          if (cmd[1] == 'R') alg[i] = 2;       // IR 2
          else if (cmd[1] == 'C') alg[i] = 3;  // IC 3
        }
      }
    }
    scanf("%d", &n2);   // n2是查询个数
    for (int i = 0; i < n2; i++) {
      scanf("%d %d", &rr, &cc);
      int orig_rr = rr, orig_cc = cc;
      is_gone = 0;
      for (int j = 0; j < n; j++) {
// printf("para_n[%d]=%d\n", j, para_n[j]);
        switch (alg[j]) {
          case 0: {
            del_r(a_para[j], para_n[j], &rr, &cc);
            break;
          }
          case 1: {
            del_c(a_para[j], para_n[j], &rr, &cc);
            break;
          }
          case 2: {
            ins_r(a_para[j], para_n[j], &rr, &cc);
            break;
          }
          case 3: {
            ins_c(a_para[j], para_n[j], &rr, &cc);
            break;
          }
          case 4: {
            exc(a_para[j], para_n[j], &rr, &cc);
            break;
          }
          default:
            break;
        }
      }
      if (is_gone) {
        printf("Cell data in (%d,%d) GONE\n", orig_rr, orig_cc);
      } else { printf("Cell data in (%d,%d) moved to (%d,%d)\n",
                      orig_rr, orig_cc, rr, cc);
      }
    }
  }
}

/*
6 6
6
EX 6 5 4 2
DC 2 1 5
EX 6 2 6 3
EX 3 1 5 4
IC 3 2 3 5
EX 3 4 2 6
20
2 5
5 2
6 3
5 4
2 1
1 4
6 2
1 3
4 1
1 6
1 5
6 5
6 4
3 1
5 3
3 5
5 5
4 5
4 3
2 6
*/
