// copyright [2018] <mituh>
// UVa 489, Hangman Judge(刽子手游戏)
#include <stdio.h>
#include <string.h>

/*
char* simp(char* ans) {
  // 归并字符 chesse -> ches
  char ans_simp[26] = {};
  char alpha[] = "abcdefghijklmnopqrstuvwxyz";
  int n = strlen(ans), cnt = 0;
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < n; j++) {
      if (alpha[i] == ans[j]) {
        ans_simp[cnt++] = alpha[i];
        break;
      }
    }
  }
  printf("ans = %s\n", ans);
  printf("simp() = %s\n", ans_simp);
  return ans_simp;
}
*/

int judge(char ans[], const char guess[]) {
  // guess能否在错6次以内猜出answer
  // chess, ches => 1
  // chess, abcdefg
  // 1, 每次猜中, 将ans中的对应字符标记成sloved
  // 2, 错误的答案wrong_cnt++, 七笔lose return 0
  // 3, 每个错误答案只记一次
  // 4, 猜测字符结束前, wrong_cnt一旦超过7, lose
  // 5, 猜测字符结束后, 既没有win, 也没lose, chickens out
  // 核心: 猜对过的再猜, 算做错; 猜错过的再猜, 算错;
  int n = strlen(ans), m = strlen(guess);
  // 归并字符 chesse -> ches
  char ans_simp[26] = {};
  char alpha[] = "abcdefghijklmnopqrstuvwxyz";
  int cnt = 0;
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < n; j++) {
      if (alpha[i] == ans[j]) {
        ans_simp[cnt++] = alpha[i];
        break;
      }
    }
  }
  // printf("-- ans_simp = %s\n   guess = %s\n", ans_simp, guess);

  int wrong_cnt = 0, right_cnt = 0;
  // 判断所猜测的字符
  for (int i = 0; i < m; i++) {
    int find = 0;
    for (int j = 0; j < cnt; j++) {
      if (guess[i] == ans_simp[j]) {
        find = 1;
        ans_simp[j] = ' ';    // 猜中过一次, 将该字符置空, 再猜算错
        right_cnt++;
        break;
      }
    }
    if (!find) {
      wrong_cnt++;  // 猜错或猜了一个已经猜对过的
    }
    // 归并后的字符每个都出现
    if (right_cnt == cnt) return 1;
    // 错误次数过6
    if (wrong_cnt == 7) return 0;
  }
  // 循环结束, 没有猜对, 但错误次数还没到限制  => 猜重复错误的也算放弃
  return -1;
}

int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("b.out", "w", stdout);
#endif
  int kase;
  while (scanf("%d", &kase) != EOF && (kase != -1)) {
    char ans[100] = {};
    char guess[100] = {};
    if (scanf("%s %s", ans, guess) != EOF) {
      printf("Round %d\n", kase);
      int r = judge(ans, guess);
      if (r == 0) {
        printf("You lose.\n");
      } else if (r == 1) {
        printf("You win.\n");
      } else {
        printf("You chickened out.\n");
      }
    }
  }
  return 0;
}
