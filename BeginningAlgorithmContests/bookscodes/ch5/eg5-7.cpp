// copyright [2018] <mituh>
// UVa 136 Ugly Numbers (丑数)
/*
  思路:
  1, 除235以外的1500个素数给计算出来, 再从5开始判断是否会被其中的某个数整除, 1500*1500*1500(n^3)
  2, 已经有丑数x, 计算2x, 3x, 5x, (他们一定不能被除了235外的其他素数整除, 如果能整除, 其他素数就不是素数 )
  用优先队列dq存放用于生成丑数的丑数, 队首是最小数,
  生成新的丑数后队首出dq栈, 判断生成数是否已经在之前出现过.
  没出现过的加入ugly_set, push入dq栈队尾
  入完ugly_set栈, 检测数量是不是到了1500

  // 检测ugly_set数量是1500存在bug, 直接让他生成1500次, 1500次的pq队首
  // The 1500'th ugly number is -1735655424. 需要定义LL
  // 不是用set来计数, 而是用pq操作的次数来计数uglynumber的数量, set只是用来判断生成数是否之前出现过
 */

#include <cstdio>
#include <set>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long LL;

struct cmp {
  bool operator() (const LL a, const LL b) const {
    return a > b;   // a>b, a的优先级比b小, 返回true
  }
};

set<LL> ugly;
// priority_queue<LL> pq;   // priority_queue<LL> pq; 这样定义数越大优先级越高
priority_queue<LL, vector<LL>, cmp > pq;
// priority_queue<LL, vector<LL>, greater<LL> > pq;   // 等价

const int multi[3] = {2, 3, 5};

int main() {
  int n = 1500;
  pq.push(1); ugly.insert(1);
  for (int i = 1; ; i++) {
    LL x = pq.top(); pq.pop();
    if (i == n) {
      printf("The 1500'th ugly number is %lld.\n", x);
      break;
    }
    for (int j = 0; j < 3; j++) {
      LL x2 = x * multi[j];
      if (!ugly.count(x2)) { pq.push(x2); ugly.insert(x2);}
    }
  }

  // 对set进行排序(set已经排序好了, 不需要重排)
  // set<int>::iterator it = ugly.end();
  // printf("The 1500'th ugly number is %d.\n", *(--it));  // 不是用set来计数
  return 0;
}
