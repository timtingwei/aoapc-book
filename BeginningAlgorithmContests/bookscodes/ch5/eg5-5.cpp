// copyright [2018] <mituh>
// UVa 12096 The SetStack Computer(集合栈计算机)
// why? 对set的一些操作不是很理解, 对ID来代表一个set不是很习惯

#include <cstdio>
#include <iostream>
#include <stack>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
// using std::stack; using std::set; using std::map;
// using std::string; using std::vector;
// using std::cin; using std::cout; using std::endl;
using namespace std;

typedef set<int> Set;
map<Set, int> IDcache;    // 把集合映射到ID
vector<Set> Setcache;     // 根据ID取集合

// 查找给定集合的ID, 如果找不到重新分配一个
int ID(Set x) {
  if (IDcache.count(x)) return IDcache[x];
  Setcache.push_back(x);
// printf("IDcache[x]=%lu\n", Setcache.size() - 1);
  return IDcache[x] = Setcache.size() - 1;
}

#define ALL(x) x.begin(), x.end()
#define INS(x) inserter(x, x.begin())


int main() {
  stack<int> s;   // 题目中的栈
  s.push(ID(Set()));

  int T, n;
  if (scanf("%d", &T) == 1) {
    while (T--) {
      cin >> n;
      for (int i = 0; i < n; i++) {
        string op;
        cin >> op;
        if (op[0] == 'P') s.push(ID(Set()));
        else if (op[0] == 'D') s.push(s.top());
        else {
          Set x1 = Setcache[s.top()]; s.pop();
          Set x2 = Setcache[s.top()]; s.pop();
          Set x;
          if (op[0] == 'U') set_union(ALL(x1), ALL(x2), INS(x));  // <algorithm>
          if (op[0] == 'I') set_intersection(ALL(x1), ALL(x2), INS(x));
          if (op[0] == 'A') {x = x2; x.insert(ID(x1));}
          s.push(ID(x));
        }
        cout << Setcache[s.top()].size() << endl;
      }
      cout << "***" << endl;
    }
  }
  
  return 0;
}
