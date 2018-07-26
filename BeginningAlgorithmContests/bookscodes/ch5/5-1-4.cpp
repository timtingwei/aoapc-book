// copyright [2018] <mituh>
// 5-1-4 结构体struct
// 添加成员函数, 构造函数, 重载运算符
#include <cstdio>
#include <iostream>
using namespace std;

// C实现一个Point结构体
struct Point_c {
  int x, y;
};

// C++实现Point结构体, 使其可以相加, io输出
struct Point {
  int x, y;
  // Point(int a, int b) : x(a), y(b) {}
  Point(int a, int b) {this->x = a; this-> y = b;}
};

Point operator + (const Point &p1, const Point &p2) {
  return Point(p1.x+p2.x, p1.y+p2.y);
}

ostream& operator << (ostream &out, const Point &p) {
  out << "(" << p.x << ", " << p.y << ")";
  return out;
}

int main() {
  struct Point_c pc;  // C实现一个Point结构体

  Point p1(1, 2), p2(3, 3);
  Point p3 = p1 + p2;
  cout << p3 << "\n";
  cout << p1 + p3 << "\n";
  return 0;
}
