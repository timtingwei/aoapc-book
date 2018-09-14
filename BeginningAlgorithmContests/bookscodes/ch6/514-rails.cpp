// Copyright[2018] <mituh>
// 514-rails.cpp

#include <cstdio>
#include <stack>
using namespace std;

int main() {
  int n;
  int i, j;
  while (scanf("%d", &n) != EOF) {
    if (!n) break;
    int over = 0;
    for (;;) {
      int ok = 1, orig_front = 1;
      stack<int> s;
      for (i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        if (!a) {over = 1; break;}
        // if (s.top() == a) {
        if (!s.empty() && s.top() == a) {    // debug01
          s.pop();
        } else {
          if (orig_front <= a && a <= n) {
            for (j = orig_front; j <= a; j++) {
              s.push(j); orig_front++;
            }
            s.pop();
          } else {
            ok = 0;
          }
        }
      }
      if (over) break;
      printf("%s\n", ok ? "Yes" : "No");
    }
    printf("\n");
  }
  return 0;
}
