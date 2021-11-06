#include<iostream>
#include<vector>
#include<string>
#include<limits.h>
#include<algorithm>
#include<numeric>
#include<unordered_set>
#include<unordered_map>
#include<cmath>
#include<stack>
using namespace std;
/*
给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。

示例 1：
输入：s = "(()"
输出：2
解释：最长有效括号子串是 "()"

示例 2：
输入：s = ")()())"
输出：4
解释：最长有效括号子串是 "()()"

示例 3：
输入：s = ""
输出：0

提示：
0 <= s.length <= 3 * 104
s[i] 为 '(' 或 ')'
*/

class Solution {
 public:
  int longestValidParentheses(string s) {
    stack<int> t;
    t.push(-1);
    int max_len = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '(') {
        t.push(i);
      } else {
        t.pop();
        if (t.empty()) {
          t.push(i);
        } else {
          max_len = max(max_len, i - t.top());
        }
      }
    }
    return max_len;
  }
};

int main() {
  int n = 101;
  vector<int> num = {1, 2, 3, 4, 5};
  string s =
    ")(()(()(((())(((((()()))((((()()(()()())())())()))()()()())(())()()(((()))))()((()))(((())()((()()())((())))(())))())((()())()()((()((())))))((()(((((()((()))(()()(())))((()))()))())";
  Solution app;
  int ans = app.longestValidParentheses(s);
  cout << ans << endl;
  return 0;
}