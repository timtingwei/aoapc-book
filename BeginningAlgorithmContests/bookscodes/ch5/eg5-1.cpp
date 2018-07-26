// copyright [2018] <mituh>
// UVa 10474 - Where is the Marble?
// 先排序sort(), 后查找lower_bound()  大于或等于x的第一个位置, 返回地址
#include <cstring>
#include <iostream>
#include <algorithm>
using std::cout; using std::cin;
using std::sort; using std::lower_bound;
const int MAXN = 100000;
int a[MAXN];

int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("b.out", "w", stdout);
#endif
  int kase = 0, n, q;
  while (scanf("%d %d", &n, &q) == 2 && n) {
    cout << "CASE# " << ++kase << ":\n";
    memset(a, 0, sizeof(a));
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);
    while (q--) {  // equal to for (int i = q; i < q; i++) {}
      int fp;
      cin >> fp;
      // 返回的是最近的指针, 与首个指针相减得到索引, 在已排序的数组a中寻找fp
      int p = lower_bound(a, a+n, fp) - a;
      if (p == n || (a[p] != fp)) {                 // 处理指针越界的情况
        cout << fp << " not found\n";
      } else {
        cout << fp << " found at " << p+1 << "\n";  // 从1开始计数
      }
    }
  }
  return 0;
}
