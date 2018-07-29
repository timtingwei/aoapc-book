// copyright [2018] <mituh>
// 实现自己的大整数类
/*
  思路: 用数组储存数字, 模拟加减乘除四则运算, 赋值, 打印等操作
  自己按照思路先实现一下:

 */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// typedef struct BigInteger {} BigInteger;   // cpp中不需要这样定义了, 直接写成struct
struct BigInteger {
  typedef long long LL;
  static const int BASE = 100000000;
  static const int WIDTH = 8;
  vector<int> s;

  // 构造函数
  BigInteger(LL num = 0) {*this = num;}  // why? 一定要定义构造函数

  // 重载赋值运算符, 一定长度内long long
  // void operator = (const LL num) {
  BigInteger operator = (LL num) {    // why? 重载运算符的函数返回类型
    s.clear();
    do {
// printf("%lld\n", num % BASE);
      s.push_back(num % BASE);
      num /= BASE;
    } while (num);
    return *this;   // why?
  }

  // 重载赋值运算符, 超过一定长度str
  BigInteger operator = (const string& str) {
    s.clear();
    int x, len = (str.length() - 1) / WIDTH + 1;
    for (int i = 0; i < len; i++) {
      int end = (str.length() - 1) - i * WIDTH;
      int start = max(0, end - WIDTH);
      sscanf(str.substr(start, end-start).c_str(), "%d", &x);
      // s.push_back(str[i] - '0');
      s.push_back(x);
    }
    return *this;   // why?
  }

  /*
  ostream& operator << (ostream &out, const BigInteger& x) {
    out << x.s.back();
    for (int i = x.s.size()-2; i >= 0; i--) {
      char buf[20];
      sprintf(buf, "08%d", x.s[i]);
      for (int j = 0; j < strlen(buf); j++) out << buf[j];
    }
    return out;
  }

  istream& operator >> (istream &in, BigInteger& x) {
    string s;
    if (!(in >> s)) return in;
    x = s;
    return in;
  }
  */

  BigInteger operator + (const BigInteger& b) const {
    BigInteger c;
    c.s.clear();
    for (int i = 0, g = 0; ; i++) {
      if (g == 0 && i >= s.size() && i >= b.s.size()) break;
      int x = g;
      if (i < s.size()) x += s[i];
      if (i < b.s.size()) x += b.s[i];
      c.s.push_back(x % BASE);
      g = x / BASE;
    }
    return c;
  }

  BigInteger operator += (const BigInteger& b) {
    *this = *this + b; return *this;
  }

  // 比较操作符
  bool operator < (const BigInteger& b) const {
    if (s.size() != b.s.size()) return s.size() < b.s.size();
    for (int i = s.size() - 1; i >= 0; i--) {
      if (s[i] != b.s[i]) return s[i] < b.s[i];
    }
    return false;  // 相等
  }

  // 定义完小于后可以定义其他所有运算符
  bool operator > (const BigInteger& b) const { return b < *this;}
  bool operator <= (const BigInteger& b) const { return !(b < *this);}
  bool operator >= (const BigInteger& b) const { return !(*this < b);}
  bool operator != (const BigInteger& b) const { return (b < *this) || (*this < b);}
  bool operator == (const BigInteger& b) const { return !(b < *this) && (*this < b);}
};


ostream& operator << (ostream &out, const BigInteger& x) {
  out << x.s.back();
  for (int i = x.s.size()-2; i >= 0; i--) {
    char buf[20];
    sprintf(buf, "08%d", x.s[i]);
    for (int j = 0; j < strlen(buf); j++) out << buf[j];
  }
  return out;

  
}

istream& operator >> (istream &in, BigInteger& x) {
  string s;
  if (!(in >> s)) return in;
  x = s;
  return in;
}


  

typedef BigInteger Int;

int main() {

  BigInteger a = 5551234567890;
  // BigInteger b = "8888888345678901234567890";
  BigInteger c = 21312312323123232;
  c += a;
  cout << a + c << "\n";
  cout << (a < c) << "\n";

  return 0;
}
