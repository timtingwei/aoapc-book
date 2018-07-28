// copyright [2018] <mituh>
// UVa 540 Time Queue 团体队列
#include <cstdio>
#include <queue>
#include <map>
using namespace std;
const int MAXN = 1050;   // 最多有1000支队伍

int main() {
  map<int, int> team;
  int t, kase = 0;
  while (scanf("%d", &t) == 1 && t) {
    printf("Scenario #%d\n", ++kase);
    // 读入每个成员的队伍编号
    for (int i = 0; i < t; i++) {
      int n, x;
      scanf("%d", &n);
      while (n--) {scanf("%d", &x); team[x] = i;}
    }

    // 模拟
    char cmd[10];
    queue<int> q, q2[MAXN];    // q队伍编号, q2是每个队伍中成员编号
    for (;;) {
      scanf("%s", cmd);
      if (cmd[0] == 'S') break;
      if (cmd[0] == 'E') {
        int x;
        scanf("%d", &x);
        // 成员所属的队伍编号是否在q中, 如果不在, q中push入队伍编号
        // q2中push入成员编号
        int t = team[x];
        if (q2[t].empty()) q.push(t);   // 检测q2[t]空, 判断q中是否有该队伍编号
        // if (q.count(team[x])) q.push(team[x]);
        q2[t].push(x);
      } else if (cmd[0] == 'D') {
        int t = q.front();   // 队首是哪个队伍
        printf("%d\n", q2[t].front()); q2[t].pop();
        if (q2[t].empty()) q.pop();   // 队首队伍中成员编号空, 移除这个队
      }
    }
    printf("\n");
  }
  return 0;
}

/*
2
3 101 102 103
3 201 202 203
ENQUEUE 101
ENQUEUE 201
ENQUEUE 102
ENQUEUE 202
ENQUEUE 103
ENQUEUE 203
DEQUEUE
DEQUEUE
DEQUEUE
DEQUEUE
DEQUEUE
DEQUEUE
STOP
Scenario #1
101
102
103
201
202
203


2
5 259001 259002 259003 259004 259005
6 260001 260002 260003 260004 260005 260006
ENQUEUE 259001
ENQUEUE 260001
ENQUEUE 259002
ENQUEUE 259003
ENQUEUE 259004
ENQUEUE 259005
DEQUEUE
DEQUEUE
ENQUEUE 260002
ENQUEUE 260003
DEQUEUE
DEQUEUE
DEQUEUE
DEQUEUE
STOP
0
Scenario #2
259001
259002
259003
259004
259005
260001

2
3 101 102 103
3 201 202 203
ENQUEUE 101
ENQUEUE 201
ENQUEUE 102
ENQUEUE 202
ENQUEUE 103
ENQUEUE 203
DEQUEUE
DEQUEUE
DEQUEUE
DEQUEUE
DEQUEUE
DEQUEUE
STOP
2
5 259001 259002 259003 259004 259005
6 260001 260002 260003 260004 260005 260006
ENQUEUE 259001
ENQUEUE 260001
ENQUEUE 259002
ENQUEUE 259003
ENQUEUE 259004
ENQUEUE 259005
DEQUEUE
DEQUEUE
ENQUEUE 260002
ENQUEUE 260003
DEQUEUE
DEQUEUE
DEQUEUE
DEQUEUE
STOP
0
*/
