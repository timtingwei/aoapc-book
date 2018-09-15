// copyright [2018] <mituh>
// 5-1-3 字符串
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <ctime>
#include <vector>
#include <stack>
#include <queue>
#include <cstdlib>

using std::cin; using std::cout;
using std::string; using std::stringstream;
using std::sort;
using std::vector;
using std::stack;
using std::priority_queue;
using std::sort;


int foo_1() {
  int c, sum = 0;
  while ((c = getchar()) != EOF) {
    if (c != ' ' && c != '\r' && c != '\n') {
      sum += (c - '0'); printf("c=%c\n", c);
    }
  }
  printf("%d\n", sum);
  printf("Time used = %.6f\n", (double)clock() / CLOCKS_PER_SEC);
  // Time used = 0.003234
  return 0;
}

int foo_1_2() {
  string line;
  while (getline(cin, line)) {
    int sum = 0, x;
    stringstream ss(line);
    while (ss >> x) sum += x;
    cout << sum << "\n";
  }
  printf("Time used = %.6f\n", static_cast<double>(clock()) / CLOCKS_PER_SEC);
  // Time used = 0.003314
  return 0;
}

int sort_v() {
  int a[] = {1, 3, 4, 5, 6};
  vector<int> ivec = {2, 8, 4, 2, 3, 4, 1, -10};
  int n = 5, m = 8;
  sort(a, a+n);
  auto begin = ivec.begin(), end = begin + m;
  sort(begin, end);   // 对vector排序要用sort(v.begin(), v.end())的方式

  for (int i = 0; i < n; i++) printf("%d ", a[i]);
  printf("\n");
  for (int i = 0; i < m; i++) printf("%d ", ivec[i]);
  printf("\n");

  return 0;
}

void test_vector() {
  vector<int> ivec = {2, 3, 4, 5};
  ivec.push_back(7);
  ivec.push_back(1);
  for (int i = 0; i < ivec.size(); i++) printf("%d ", ivec[i]);
  printf("\n");
  ivec.pop_back();
  for (int i = 0; i < ivec.size(); i++) printf("%d ", ivec[i]);
  printf("\n");
  ivec.resize(3);
  for (int i = 0; i < ivec.size(); i++) printf("%d ", ivec[i]);
  printf("\n");
  
}

void test_stack() {
  stack<int> s;
  s.push(17);
  s.push(5);
  s.push(123);
  s.push(25);
  s.push(12);
  cout << s.top() << "\n";
  s.pop();
  cout << s.top() << "\n";
  // int i = s.pop();
  // cout << i << "\n";
  // i = s.pop();
  // cout << i << "\n";
  // for (int i = )
}

struct cmp {
  bool operator() (const int a, const int b) const {
    // a的优先级比b小的时候, 返回true
    return a%10 > b%10;
  }
};

// 测试优先队列
void test_priority_queue() {
  priority_queue<int> pq;
  pq.push(5);
  pq.push(3);
  pq.push(10);
  pq.push(8);
  printf("%d\n", pq.top());
  pq.pop();
  printf("%d\n", pq.top());
  pq.pop();
  printf("%d\n", pq.top());
  priority_queue<int, vector<int>, cmp > pq1;
  pq1.push(5);
  pq1.push(3);
  pq1.push(9);
  pq1.push(8);
  printf("%d\n", pq1.top());
  pq1.pop();
  printf("%d\n", pq1.top());
  pq1.pop();
  printf("%d\n", pq1.top());
}


// 测试stl
void test_stl() {
  // vector<int> vec = {3, 2, 4};
  // sort(vec, vec+3);
  int a[] = {3, 2, 4};
  sort(a, a+3);
  printf("%d %d %d\n", a[0], a[1], a[2]);
  printf("%d\n", rand()%10);
  printf("%f\n", (double)rand() / RAND_MAX * 101);
}

void fill_random_int(vector<int> &v, int cnt) {
  v.clear();
  for (int i = 0; i < cnt; i++) {
    v.push_back(rand());
  }
}

void test_sort(vector<int> &v) {
  sort(v.begin(), v.end());
  for (int i = 0; i < v.size()-1; i++) {
    assert(v[i] <= v[i+1]);
    // if (v[i] > v[i+1]) {printf("Error:v[i]>v[i+1]!\n"); abort();}
  }
}

int test_random_vector() {
  vector<int> v;
  fill_random_int(v, 1000000);
  test_sort(v);
  return 0;
}

int main() {
  srand(time(NULL));
  // sort_v();
  // test_vector();
  // test_stack();
  // test_priority_queue();
  // test_stl();
  // test_fill_random_int();
  test_random_vector();
  return 0;
}
