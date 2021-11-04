#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
#include<numeric>
/*
给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。
返回 s 所有可能的分割方案。
示例: 输入: "aab" 输出: [ ["aa","b"], ["a","a","b"] ]
*/
using namespace std;
class Solution {
 public:
  vector<vector<string> > result;
  vector<string> path;
  void backTracking(const string &s, int startindex) {
    if (startindex >= s.size()) {
      result.push_back(path);
      return;
    }
    for (int i = startindex; i < s.size(); i++) {
      if (!isPalindrome(s, startindex, i)) {
        continue;
      }
      string str = s.substr(startindex, i - startindex + 1);
      path.push_back(str);
      backTracking(s, i + 1);
      path.pop_back();
    }
  }
  bool isPalindrome(string s, int left, int right) {
    while (left <= right) {
      if (s[left] != s[right]) {
        return false;
      }
      left++;
      right--;
    }
    return true;
  }
  vector<vector<string> > partition(string s) {
    backTracking(s, 0);
    return result;
  }
};

int main() {
  string target = "qbcknf";
  Solution app;
  vector<vector<string> > ans = app.partition(target);
  cout << ans[1].size() << endl;
  return 0;
}