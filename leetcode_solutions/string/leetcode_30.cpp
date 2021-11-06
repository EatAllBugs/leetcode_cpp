#include<iostream>
#include<vector>
#include<string>
#include<limits.h>
#include<algorithm>
#include<numeric>
#include<unordered_set>
#include<unordered_map>
#include<cmath>
using namespace std;
/*

给定一个字符串 s 和一些 长度相同 的单词 words 。
找出 s 中恰好可以由 words 中所有单词串联形成的子串的起始位置。

注意子串要与 words 中的单词完全匹配，中间不能有其他字符 ，但不需要考虑 words 中单词串联的顺序。

输入：s = "barfoothefoobarman", words = ["foo","bar"]
输出：[0,9]
解释：
从索引 0 和 9 开始的子串分别是 "barfoo" 和 "foobar" 。
输出的顺序不重要, [9,0] 也是有效答案

输入：s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
输出：[6,9,12]

*/

class Solution {
 public:
  vector<int> findSubstring(string s, vector<string> &words) {
    vector<int> ans;
    if (s.empty() || words.empty()) {
      return ans;
    }
    int n = words.size(), m = words[0].size();
    int len = n * m;
    if (len > s.size()) {
      return ans;
    }
    unordered_map<string, int> m1;
    for (auto &word : words) {
      m1[word]++;
    }
    for (int i = 0; i <= s.size() - len; i++) {
      string temp = s.substr(i, len);
      int sum = 0;
      unordered_map<string, int> m2;
      for (int j = 0; j <= temp.size() - m; j += m) {
        string str = temp.substr(j, m);
        if (m1.find(str) == m1.end()) {
          break;
        }
        m2[str]++;
        if (m2[str] > m1[str]) {
          break;
        }
        sum++;
      }
      if (sum == n) {
        ans.push_back(i);
      }
    }
    return ans;
  }
};

int main() {
  int n = 101;
  vector<int> num = {1, 2, 3, 4, 5};
  string s = "a";
  vector<string> words = {"a", "a"};
  Solution app;
  vector<int> ans = app.findSubstring(s, words);
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << endl;
  }
  //cout << ans << endl;
  return 0;
}