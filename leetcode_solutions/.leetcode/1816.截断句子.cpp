/*
 * @lc app=leetcode.cn id=1816 lang=cpp
 *
 * [1816] 截断句子
 */

// @lc code=start
class Solution {
 public:
  string truncateSentence(string s, int k) {
    int n = s.size();
    int end = 0, count = 0;;
    for (int i = 1; i <= n; i++) {
      if (i == n || s[i] == ' ') {
        count++;
      }
      if (count == k) {
        end = i;
        break;
      }
    }
    return  s.substr(0, end);
  }
};
// @lc code=end

