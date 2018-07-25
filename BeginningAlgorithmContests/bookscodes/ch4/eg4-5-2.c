// copyright [2018] <mituh>
// UVa 521 Spreadsheet Tracking 追踪电子表格中的单元格 struct-simulate
/*
  思路:
  1, 只对需要查询的数据(a,b)进行计算
  2, 将操作指令相关的数据, 放在struct中
  3, 不同的(a,b)进行同一组操作simulate()
  
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
0 0
output:
Spreadsheet #1
Cell data in (4,8) moved to (4,6)
Cell data in (5,5) GONE
Cell data in (7,8) moved to (7,6)
Cell data in (6,5) moved to (1,2)
*/

#include <stdio.h>
#include <string.h>
#define MAXD 10000

struct Command {
  char ch[5];
  int a[50], n;
} cmd[MAXD]; int cn;   // 有cn条操作指令



int simulate(int* rr, int* cc) {
  // 根据cmd中的数据, 对行列进行统一操作, GONE -> 0, 否则返回 -> 1
  for (int i = 0; i < cn; i++) {
    if (cmd[i].ch[0] == 'E') {
// printf("r1=%d, c1=%d, r2=%d, c2=%d\n",
//       cmd[i].a[0], cmd[i].a[1], cmd[i].a[2], cmd[i].a[3]);
      if (cmd[i].a[0] == *rr && cmd[i].a[1] == *cc) {
        *rr = cmd[i].a[2]; *cc = cmd[i].a[3];
      } else if (cmd[i].a[2] == *rr && cmd[i].a[3] == *cc) {
        *rr = cmd[i].a[0]; *cc = cmd[i].a[1];
      }
    } else {
      int dr = 0, dc = 0;
      for (int j = 0; j < cmd[i].n; j++) {   // 尽量减少遍历的次数
        int x = cmd[i].a[j];
        if (cmd[i].ch[0] == 'I') {
          if (cmd[i].ch[1] == 'R' && x <= *rr) dr++;
          else if (cmd[i].ch[1] == 'C' && x <= *cc) dc++;
        } else {
          if (cmd[i].ch[1] == 'R' && x == *rr) return 0;
          else if (cmd[i].ch[1] == 'C' && x == *cc) return 0;
          if (cmd[i].ch[1] == 'R' && x < *rr) dr--;
          else if (cmd[i].ch[1] == 'C' && x < *cc) dc--;
        }
      }
      (*rr) += dr; (*cc) += dc;
    }
  }

  return 1;
}

int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("b.out", "w", stdout);
#endif
  int r, c, kase = 0;
  while (scanf("%d %d", &r, &c) == 2 && r) {
    memset(cmd, 0, sizeof(cmd));
    if (kase) printf("\n");
    printf("Spreadsheet #%d\n", ++kase);
    scanf("%d", &cn);
    for (int i = 0; i < cn; i++) {
      scanf("%s", cmd[i].ch);
      if (cmd[i].ch[0] == 'E') {
        for (int j = 0; j < 4; j++) scanf("%d", &cmd[i].a[j]);
      } else {
        scanf("%d", &cmd[i].n);
        for (int j = 0; j < cmd[i].n; j++) scanf("%d", &cmd[i].a[j]);
      }
    }
    int dn, rr, cc;   // 查询数据个数
    scanf("%d", &dn);
    for (int i = 0; i < dn; i++) {
      scanf("%d %d", &rr, &cc);
      int origr = rr, origc = cc;
      if (!simulate(&rr, &cc)) {
        printf("Cell data in (%d,%d) GONE\n", origr, origc);
      } else {
        printf("Cell data in (%d,%d) moved to (%d,%d)\n",
               origr, origc, rr, cc);
      }
    }
  }
  return 0;
}
