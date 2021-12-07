/*
 * @lc app=leetcode.cn id=166 lang=cpp
 *
 * [166] 分数到小数
 */

// @lc code=start
class Solution {
 public:
  string fractionToDecimal(int numerator, int denominator) {
    string ans = "";
    if (denominator == 0) {
      return ans;
    }
    if (numerator > 0 && denominator < 0 || numerator < 0 && denominator > 0) {
      ans += "-";
    }
  }
};
// @lc code=end

