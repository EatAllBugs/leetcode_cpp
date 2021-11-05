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
给你一个字符串 s 和一个字符串列表 wordDict 作为字典，
判定 s 是否可以由空格拆分为一个或多个在字典中出现的单词。

说明：拆分时可以重复使用字典中的单词。 

示例 1：
输入: s = "leetcode", wordDict = ["leet", "code"]
输出: true
解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。
示例 2：

输入: s = "applepenapple", wordDict = ["apple", "pen"]
输出: true
解释: 返回 true 因为 "applepenapple" 可以被拆分成 "apple pen apple"。
     注意你可以重复使用字典中的单词。
示例 3：

输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
输出: false
*/

class Solution {
 public:
  bool wordBreak(string s, vector<string> &wordDict) {
  }
};

int main() {
  int n = 101;
  vector<int> num = {1, 2, 3, 4, 5};
  string s = "sascacamca";
  Solution app;
  string ans = app.(n);
  cout << ans << endl;
  return 0;
}