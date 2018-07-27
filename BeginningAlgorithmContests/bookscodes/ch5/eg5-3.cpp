// copyright [2018] <mituh>
// UVa 10815 安迪的第一个字典
#include <cstdio>
#include <iostream>
#include <set>
#include <string>
#include <sstream>
using std::cin; using std::cout;
using std::set; using std::string; using std::stringstream;

set<string> dict;  // string集合

int main() {
  string s, buf;
  while (cin >> s) {
    for (int i = 0; i < s.length(); i++) {
      if (isalpha(s[i])) {
        s[i] = tolower(s[i]);
      } else {
        s[i] = ' ';
      }
    }
    stringstream ss(s);   // " adventures" -> "adventures"
    while (ss >> buf) dict.insert(buf);   // why?
    // dict.insert(s);
  }

  for (set<string>::iterator it = dict.begin(); it != dict.end(); ++it)
    cout << *it << "\n";
  return 0;
}
/*
Adventures in Disneyland

Two blondes were going to Disneyland when they came to a fork in the road.
The sign read: "Disneyland Left."

So they when home.
*/
