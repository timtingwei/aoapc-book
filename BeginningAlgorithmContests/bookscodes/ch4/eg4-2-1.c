// copyright [2018] <mituh>
// UVa 489, Hangman Judge(刽子手游戏)

#include <stdio.h>
#include <string.h>
int left, chance;
int win, lose;
char s[30]; char s2[30];

void guess(char ch) {
  int bad = 1;
  for (int i = 0; i < strlen(s); i++) {
    if (s[i] == ch) {
      bad = 0; s[i] = ' '; left--;
    }
  }
  if (bad) --chance;
  if (!left) win = 1;
  if (!chance) lose = 1;
}

int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("b.out", "w", stdout);
#endif
  int rnd;
  while ((scanf("%d %s %s", &rnd, s, s2) == 3) && (rnd != -1)) {
    printf("Round %d\n", rnd);
    win = 0, lose = 0;
    left = strlen(s), chance = 7;
    for (int i = 0; i < strlen(s2); i++) {
      guess(s2[i]);
      if (win || lose) break;
    }
    if (win) {
      printf("You win.\n");
    } else if (lose) {
      printf("You lose.\n");
    } else {
      printf("You chickened out.\n");
    }
  }

  return 0;
}
