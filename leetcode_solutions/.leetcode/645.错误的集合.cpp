/*
 * @lc app=leetcode.cn id=645 lang=cpp
 *
 * [645] 错误的集合
 */

// @lc code=start
class Solution {
 public:
  vector<int> findErrorNums(vector<int> &nums) {
    int n = nums.size();
      vector<int> bp(n + 1, 0);
    for (auto &n : nums) {
      bp[n]++;
    }
    vector<int> ans(2, 0);
    for (int i = 1; i <= n; i++) {
      if (bp[i] == 0) {
        ans[1] = i;
      } else if (bp[i] == 2) {
        ans[0] = i;
      } else {
        continue;
      }
    }
    return ans;
  }
};
// @lc code=end

