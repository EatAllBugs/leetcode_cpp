/*
 * @lc app=leetcode.cn id=137 lang=cpp
 *
 * [137] 只出现一次的数字 II
 */

// @lc code=start
class Solution {
 public:
  int singleNumber(vector<int> &nums) {
    int a = 0, b = 0;
    for (auto x : nums) {
      b = (b ^ x) & ~a;
      a = (a ^ x) & ~b;
    }
    return b;
  }
};
// @lc code=end

