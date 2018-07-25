// copyright [2018] <mituh>
// UVa 12412 - A typical homeword(师兄帮帮忙)
// 先框架后细节
#include <stdio.h>
#include <string.h>

struct Menu {
  char intro[100];
  int n;
  char func_n[20][50];   // 20个功能, 每个功能名字50字符以内
} mn;

/*
struct Student {
  char SID[15];
  char CID[25];
  char name[15];
  int score[5];   // chinese, math, english, programming
} stdt[110];       // 最多存放100个学生信息
*/

typedef struct {
  char SID[15];
  char CID[25];
  char name[15];
  int score[5];   // chinese, math, english, programming
  int tot, rank;
  double aveg;
} Student;
Student stdt[110];   // 最多存放100个学生信息
int stdt_n = 0;


char judge_key[25];   // 用来判断是0, 还是其他有效信息的字符串


int is_zero(char* s) {
  // 字符串s是不是"0"
  return strlen(s) == 1 && s[0] == '0';
}

int samestr(char* s1, char* s2) {
  // 判断s1, s2是否为一样
  int n = strlen(s1), m = strlen(s2);
  if (n == m) {
    for (int i = 0; i < n; i++) {
      if (s1[i] != s2[i]) return 0;
    }
  } else {return 0;}
  return 1;
}

void cpystr(char* s, char* s1) {
  memset(s, 0, sizeof(char) * strlen(s));
  memcpy(s, s1, sizeof(char) * strlen(s1));
}


int update_rank() {
  for (int i = 0; i < stdt_n; i++) {
    int r = stdt_n;
    for (int j = 0; j < stdt_n; j++) {
      if (i == j) continue;
      if (stdt[j].tot < stdt[i].tot) r--;
    }
    printf("i=%d, r=%d\n", i, r);
    stdt[i].rank = r;
  }
  return 0;
}


int del(int i) {
  // 删除索引i学生的信息
  if (i < 0 || i >= stdt_n) {printf("del:no %d student\n", i); return -1;}
  for (int x = i; x < stdt_n - 1; x++) {
    // 清空当前行
    memset(stdt[x].SID, 0, sizeof(stdt[x].SID));
    memset(stdt[x].CID, 0, sizeof(stdt[x].CID));
    memset(stdt[x].name, 0, sizeof(stdt[x].name));
    // 拷贝下一行为当前行
    cpystr(stdt[x].SID, stdt[x+1].SID);
    cpystr(stdt[x].CID, stdt[x+1].CID);
    cpystr(stdt[x].name, stdt[x+1].name);
    stdt[x].score[0] = stdt[x+1].score[1];
    stdt[x].score[1] = stdt[x+1].score[1];
    stdt[x].score[2] = stdt[x+1].score[2];
    stdt[x].score[3] = stdt[x+1].score[3];
  }
  memset(stdt[stdt_n-1].SID, 0, sizeof(stdt[stdt_n-1].SID));
  memset(stdt[stdt_n-1].CID, 0, sizeof(stdt[stdt_n-1].CID));
  memset(stdt[stdt_n-1].name, 0, sizeof(stdt[stdt_n-1].name));
  update_rank();
  stdt_n--;
// printf("del: stdt_n=%d\n", stdt_n);
  return stdt_n;
}

void printstdt() {
  // 调试函数
  printf("printstdt:\n");
  for (int i = 0; i < stdt_n; i++) {
    printf("i=%d  SID=%s, CID=%s, name=%s, chinese=%d, math=%d, english=%d, programming=%d\n",
           i,
           stdt[i].SID, stdt[i].CID, stdt[i].name,
           stdt[i].score[0], stdt[i].score[1],
           stdt[i].score[2], stdt[i].score[3]);
  }
  printf("\n");
}


int getmenu() {
  /*
  Welcome to Student Performance Management System (SPMS).
  1 - Add
  2 - Remove
  3 - Query
  4 - Show ranking
  5 - Show Statistics
  0 - Exit
  */
  cpystr(mn.intro, "Welcome to Student Performance Management System (SPMS).");
  mn.n = 6;
  cpystr(mn.func_n[0], "Exit");
  cpystr(mn.func_n[1], "Add");
  cpystr(mn.func_n[2], "Remove");
  cpystr(mn.func_n[3], "Query");
  cpystr(mn.func_n[4], "Show ranking");
  cpystr(mn.func_n[5], "Show statistics");
  return 0;
}



int add() {
  // ..
  for (;;) {
    // ..
    printf("Please enter the SID, CID, name and four scores. Enter 0 to finish.\n");
    memset(judge_key, 0, sizeof(judge_key));
    if (scanf("%s", judge_key) == 1 && (!is_zero(judge_key))) {
      // 第一个输入不是0
      Student tmp_stdt;
      scanf("%s %s %d%d%d%d",
            tmp_stdt.CID, tmp_stdt.name,
            &tmp_stdt.score[0], &tmp_stdt.score[1],
            &tmp_stdt.score[2], &tmp_stdt.score[3]);
      int ok = 1;
      for (int i = 0; i < stdt_n; i++) {
        if (samestr(stdt[i].SID, judge_key)) {ok = 0; break;}
      }
      if (ok) {
        // 不为0, 且不重复, 在添加进来
        cpystr(stdt[stdt_n].SID, judge_key);
        cpystr(stdt[stdt_n].CID, tmp_stdt.CID);
        cpystr(stdt[stdt_n].name, tmp_stdt.name);
        stdt[stdt_n].score[0] = tmp_stdt.score[0];
        stdt[stdt_n].score[1] = tmp_stdt.score[1];
        stdt[stdt_n].score[2] = tmp_stdt.score[2];
        stdt[stdt_n].score[3] = tmp_stdt.score[3];
// printf("SID=%s, CID=%s, name=%s, chinese=%d, math=%d, english=%d, programming=%d\n");
// stdt[stdt_n].SID, stdt[stdt_n].CID, stdt[stdt_n].name,
// stdt[stdt_n].score[0], stdt[stdt_n].score[1],
// stdt[stdt_n].score[2], stdt[stdt_n].score[3]);
        stdt_n++;
      } else { printf("Duplicated SID.\n");}
    } else { return 0;}
  }
  return 1;
}

int rmv() {
  // ..
  for (;;) {
    printf("Please enter SID or name. Enter 0 to finish.\n");
    memset(judge_key, 0, sizeof(judge_key));
    if (scanf("%s", judge_key) == 1) {
      if (is_zero(judge_key)) return 0;
      int dn = 0;
      for (int i = 0; i < stdt_n; i++) {
        // judge_key与数据库中的SID or name匹配
        if (samestr(judge_key, stdt[i].SID)
            || (samestr(judge_key, stdt[i].name))) {
          del(i);  // 删除该条信息
          dn++;
        }
      }
// printf("%d student(s) removed.\n", dn);
    }
  }
  return 1;
}

int update_query() {
  int t = 0; double a;
  // 计算total, averge
  for (int i = 0; i < stdt_n; i++) {
    int t = 0, r = stdt_n;
    for (int j = 0; j < 4; j++) {   // 四门课成绩
      t += stdt[i].score[j];
    }
    stdt[i].tot = t;
    stdt[i].aveg = (double)t / 4;
  }

  // 计算当前所有学生的排名, stdt
  for (int i = 0; i < stdt_n; i++) {
    int r = stdt_n;
    for (int j = 0; j < stdt_n; j++) {
      if (i == j) continue;
      if (stdt[j].tot < stdt[i].tot) r--;  // 有比他小的, rank-1
    }
    stdt[i].rank = r;
// printf("i=%d, rank=%d\n", i, stdt[i].rank);
  }

  return 0;
}


Student q_stdts[110];   // 最多存放100个学生信息, 用于query
int q_n = 0;

int clear_q_stdts() {
  for (int i = 0; i < q_n; i++) {
    // ..
    memset(q_stdts[i].SID, 0, sizeof(q_stdts[i].SID));
    memset(q_stdts[i].CID, 0, sizeof(q_stdts[i].CID));
    memset(q_stdts[i].name, 0, sizeof(q_stdts[i].name));
    memset(q_stdts[i].score, 0, sizeof(q_stdts[i].score));
    q_stdts[i].rank = 0, q_stdts[i].tot = 0, q_stdts[i].aveg = 0.0;
  }
  q_n = 0;
// printf("clear_stdti: q_n=%d\n", q_n);
  return 0;
}
/*
1
1501087 2 tim 50 50 50 50
1555555 1 tim 30 30 30 30
1111111 3 tim 80 80 80 80
1314144 2 he  20 20 20 20
2313133 1 he  40 40 40 40
0
3
tim
he
*/
int query() {
  // 根据此时数据, 对排名, 总分, 平均分进行计算(改变的是stdt)
  update_query();
  for (;;) {
    printf("Please enter SID or name. Enter 0 to finish.\n");
    clear_q_stdts();   // 每次循环清空前面的临时学生表
    memset(judge_key, 0, sizeof(judge_key));
    if (scanf("%s", judge_key) == 1) {
      if (is_zero(judge_key)) return 0;
      int dn = 0;
      for (int i = 0; i < stdt_n; i++) {
        // judge_key与数据库中的SID or name匹配
        if (samestr(judge_key, stdt[i].SID)
            || (samestr(judge_key, stdt[i].name))) {
          // q_stdts[q_n] = stdt[i];
          cpystr(q_stdts[q_n].SID, stdt[i].SID);
          cpystr(q_stdts[q_n].CID, stdt[i].CID);
          cpystr(q_stdts[q_n].name, stdt[i].name);
          q_stdts[q_n].score[0] = stdt[i].score[0];
          q_stdts[q_n].score[1] = stdt[i].score[1];
          q_stdts[q_n].score[2] = stdt[i].score[2];
          q_stdts[q_n].score[3] = stdt[i].score[3];
          q_stdts[q_n].rank = stdt[i].rank;
          q_stdts[q_n].tot = stdt[i].tot;
          q_stdts[q_n].aveg = stdt[i].aveg;
          q_n++;
        }
      }
      for (int i = 0; i < q_n; i++) {
        printf("%d %s %s %s %d %d %d %d %d %.2f\n",
               q_stdts[i].rank, q_stdts[i].SID, q_stdts[i].CID,
               q_stdts[i].name, q_stdts[i].score[0], q_stdts[i].score[1],
               q_stdts[i].score[2], q_stdts[i].score[3],
               q_stdts[i].tot, q_stdts[i].aveg);
      }
    }
  }
  return 1;
}
int showrank() {
  printf("Showing the ranklist hurts students' self-esteem. Don't do that.\n");
  return 0;
}
int showstat() {
  // ..
  return 0;
}


int startmenu() {
  printf("%s\n\n", mn.intro);
  for (int i = 1; i < mn.n; i++) { printf("%d - %s\n", i, mn.func_n[i]);}
  printf("%d - %s\n\n", 0, mn.func_n[0]);
  int c;
  if (scanf("%d", &c) == 1) {               // 选择菜单选项
    // ..
    if (c == 0) return 0;          // 暂时不抽象成函数
    else if (c == 1) add();
    else if (c == 2) rmv();
    else if (c == 3) query();
    else if (c == 4) showrank();
    else if (c == 5) showstat();
  }

  printstdt();

  return 1;
}

int main() {
  getmenu();
  for (;;) {
    if (!startmenu()) break;
  }
  return 0;
}



/*
AC的输入输出
Sample Input:
1
0011223344 1 John 79 98 91 100
0022334455 1 Tom 59 72 60 81
0011223344 2 Alice 100 100 100 100
2423475629 2 John 60 80 30 99
0
3
0022334455
John
0
5
1
2
0011223344
0
5
0
4
0



Sample Output:
$./a.out
  Welcome to Student Performance Management System (SPMS).
  1 - Add
  2 - Remove
  3 - Query
  4 - Show ranking
  5 - Show Statistics
  0 - Exit
$1
  Please enter the SID, CID, name and four scores. Enter 0 to finish.
$0011223344 1 John 79 98 91 100
  Please enter the SID, CID, name and four scores. Enter 0 to finish.
$0022334455 1 Tom 59 72 60 81
  Please enter the SID, CID, name and four scores. Enter 0 to finish.
$ 0011223344 2 Alice 100 100 100 100
  Duplicated SID.
  Please enter the SID, CID, name and four scores. Enter 0 to finish.
  2423475629 2 John 60 80 30 99
  Please enter the SID, CID, name and four scores. Enter 0 to finish.
$0
  Welcome to Student Performance Management System (SPMS).
  1 - Add
  2 - Remove
  3 - Query
  4 - Show ranking
  5 - Show Statistics
  0 - Exit
$3
  Please enter SID or name. Enter 0 to finish.
$0022334455
  2 0022334455 1 Tom 59 72 60 81 272 68.00
  Please enter SID or name. Enter 0 to finish.
$John
  1 0011223344 1 John 79 98 91 100 368 92.00
  3 2423475629 2 John 60 80 30 99 269 67.25
  Please enter SID or name. Enter 0 to finish.
$0
  Welcome to Student Performance Management System (SPMS).
  1 - Add
  2 - Remove
  3 - Query
  4 - Show ranking
  5 - Show Statistics
  0 - Exit
$5
  Please enter class ID, 0 for the whole statistics.
$1
  Chinese
  Average Score: 69.00
  Number of passed students: 1
  Number of failed students: 1
  Mathematics
  Average Score: 85.00
  Number of passed students: 2
  Number of failed students: 0
  English
  Average Score: 75.50
  Number of passed students: 2
  Number of failed students: 0
  Programming
  Average Score: 90.50
  Number of passed students: 2
  Number of failed students: 0
  Overall:
  Number of students who passed all subjects: 1
  Number of students who passed 3 or more subjects: 2
  Number of students who passed 2 or more subjects: 2
  Number of students who passed 1 or more subjects: 2
  Number of students who failed all subjects: 0
  Welcome to Student Performance Management System (SPMS).
  1 - Add
  2 - Remove
  3 - Query
  4 - Show ranking
  5 - Show Statistics
  0 - Exit
$2
  Please enter SID or name. Enter 0 to finish.
$0011223344
  1 student(s) removed.
  Please enter SID or name. Enter 0 to finish.
0
5
0
4
0
  Welcome to Student Performance Management System (SPMS).
  1 - Add
  2 - Remove
  3 - Query
  4 - Show ranking
  5 - Show Statistics
  0 - Exit
  Please enter class ID, 0 for the whole statistics.
  Chinese
  Average Score: 59.50
  Number of passed students: 1
  Number of failed students: 1
  Mathematics
  Average Score: 76.00
  Number of passed students: 2
  Number of failed students: 0
  English
  Average Score: 45.00
  Number of passed students: 1
  Number of failed students: 1
  Programming
  Average Score: 90.00
  Number of passed students: 2
  Number of failed students: 0
  Overall:
  Number of students who passed all subjects: 0
  Number of students who passed 3 or more subjects: 2
  Number of students who passed 2 or more subjects: 2
  Number of students who passed 1 or more subjects: 2
  Number of students who failed all subjects: 0
  Welcome to Student Performance Management System (SPMS).
  1 - Add
  2 - Remove
  3 - Query
  4 - Show ranking
  5 - Show Statistics
  0 - Exit
  Showing the ranklist hurts students’ self-esteem. Don’t do that.
  Welcome to Student Performance Management System (SPMS).
  1 - Add
  2 - Remove
  3 - Query
  4 - Show ranking
  5 - Show Statistics
  0 - Exit

*/
