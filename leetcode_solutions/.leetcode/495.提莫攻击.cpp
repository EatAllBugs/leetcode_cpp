/*
 * @lc app=leetcode.cn id=495 lang=cpp
 *
 * [495] 提莫攻击
 */

// @lc code=start
class Solution {
 public:
  int findPoisonedDuration(vector<int> &timeSeries, int duration) {
    int n = timeSeries.size();
    int ans = duration;
    for (int i = 0; i < n - 1; i++) {
      ans += min(timeSeries[i + 1] - timeSeries[i], duration);
    }
    return ans;
  }
};
// @lc code=end

