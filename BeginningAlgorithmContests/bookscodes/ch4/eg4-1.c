// copyright [2018] <mituh>
// 例题4-1 UVa 1339 - Ancient Cipher(古老的密码)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 100 + 10
char s1[MAXN];
char s2[MAXN];

int cmp(const void *a, const void *b) {
  return *(int *)a - *(int *)b;
}

int main() {
  while (scanf("%s %s", s1, s2) == 2) {
    int n = strlen(s1);
    char alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int cnt1[26], cnt2[26];
    memset(cnt1, 0, sizeof(cnt1));
    memset(cnt2, 0, sizeof(cnt2));
    for (int i = 0; i < 26; i++) {
      for (int j = 0; j < n; j++) {
        if (alpha[i] == s1[j]) cnt1[i]++;
        if (alpha[i] == s2[j]) cnt2[i]++;
      }
    }
    qsort(cnt1, 26, sizeof(int), cmp);
    qsort(cnt2, 26, sizeof(int), cmp);
    int ok = 1;
    for (int i = 0; i < 26; i++) {
      if (cnt1[i] != cnt2[i]) { ok = !ok; printf("NO\n"); break;}
    }
    if (ok) printf("YES\n");
  }

  return 0;
}
