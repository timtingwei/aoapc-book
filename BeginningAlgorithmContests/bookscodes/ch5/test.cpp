// copyright [2018] <mituh>
// 5-1-3 字符串
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <ctime>
using std::cin; using std::cout;
using std::string; using std::stringstream;


int main() {
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

int foo() {
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
