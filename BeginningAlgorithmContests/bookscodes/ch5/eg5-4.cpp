// copyright [2018] <mituh>
// UVa 156 Ananagrams(反片语)
/*
先标准化单词, 用map计数为1的单词, 满足条件
ladder came tape soon leader acme RIDE lone Dreis peat
 ScAlE orb  eye  Rides dealer  NotE derail LaCeS  drIed
noel dire Disk mace Rob dries
#
 */
#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using std::cin; using std::cout;
using std::map; using std::vector;
using std::string; using std::stringstream;

map<string, int> cnt;
vector<string> words;

string repr(string s) {
  // 标准化s, 全小写, 从小到大sort
  string ans;        // 如果string ans = s; 就可以用索引修改
  for (int i = 0; i < s.length(); i++) {
    ans.push_back(tolower(s[i]));
  }
  sort(ans.begin(), ans.end());
  return ans;
}

int main() {
  string s;
  while (cin >> s) {
    if (s == "#") break;
    words.push_back(s);
    string r = repr(s);
    if (!cnt.count(r)) cnt[r] = 0;    // 先初始化为0 why?
    cnt[r]++;
  }
  vector<string> ans;
  for (int i = 0; i < words.size(); i++) {
    if ((cnt[repr(words[i])]) == 1) ans.push_back(words[i]);
  }
  sort(ans.begin(), ans.end());
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << "\n";
  }
  return 0;
}
