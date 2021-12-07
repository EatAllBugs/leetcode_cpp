#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
#include<numeric>
#include<unordered_set>
#include<map>
using namespace std;
/*
给定两个字符串 s 和 t，判断它们是否是同构的。

如果 s 中的字符可以按某种映射关系替换得到 t ，那么这两个字符串是同构的。

每个出现的字符都应当映射到另一个字符，同时不改变字符的顺序。

不同字符不能映射到同一个字符上，相同字符只能映射到同一个字符上，字符可以映射到自己本身。
*/

class Solution {
 public:
  bool isIsomorphic(string s, string t) {
    unordered_map<char, char> s1;
    unordered_map<char, char> t1;
    for (int i = 0; i < s.size(); i++) {
      char x = s[i];
      char y = t[i];
      if (s1.count(x) && s1[x] != y || t1.count(y) && t1[y] != x) {
        return false;
      }
      s1[x] = y;
      t1[y] = x;
    }
    return true;
  }
};

int main() {
  vector<string> g = {"eat", "tea", "tan", "ate", "nat", "bat"};
  Solution app;
  vector<vector<string> > ans = app.isIsomorphic(g);
  cout << ans.size() << endl;
  return 0;
}