// copyright [2018] <mituh>
// 5-1-5, 模版template
#include <iostream>
using namespace std;

// 将point改写成template, 可以传入double其他类型
template <typename T>
struct Point {
  T x, y;
  Point(T a, T b) : x(a), y(b) {}
  // Point(T a=0, T b=0) {this->x = a; this-> y = b;}
};

template <typename T>
Point<T> operator + (const Point<T> &p1, const Point<T> &p2) {
  return Point<T>(p1.x+p2.x, p1.y+p2.y);
}

template <typename T>
ostream& operator << (ostream &out, const Point<T> &p) {
  out << "(" << p.x << ", " << p.y << ")";
  return out;
}

// 为template sum 定义+= 运算符
template <typename T>
Point<T> operator += (Point<T> &p1, const Point<T> &p2) {
  p1 = p1 + p2;
  return p1;
}

/*
int sum(int* begin, int* end) {
  int ans = 0;
  for (int *it = begin; it != end; it++) ans += (*it);
  return ans;
}
*/

/*
// 将sum改写成模版, 为double和Point类型求和
template <typename T>
T sum(T* begin, T* end) {
  T ans = T();
  // for (T* it = begin; it != end; it++) ans = ans + (*it);  // Point只定义+, 没定义+=
  for (T* it = begin; it != end; it++) ans += (*it);  // 定义+=之后
  return ans;
}
*/


int a[12] = {0, 1, 2, 3, 4};
int n = 5;
int main() {
  // printf("sum=%d\n", sum(a, a+n));

  // double da[] = {1.1, 2.2, 3.3, 4.4, 5.5};
  // cout << sum(da, da + 5) << "\n";
  // Point<int> pa[] = { Point<int>(1, 2), Point<int>(3, 2), Point<int>(2, 2) };
  // cout << sum(pa, pa + 3) << "\n";
  Point<int> a(1, 2), b(3, 4);
  Point<double> c(1.1, 2.2), d(3.3, 4.4);
  cout << a + b << " " << c + d << "\n";

  return 0;
}
