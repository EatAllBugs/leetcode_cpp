/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 轮转数组
 */

// @lc code=start
class Solution {
 public:
  void rotate(vector<int> &nums, int k) {
    int n = nums.size();
    k %= n;
    vector<int> temp = nums;
    for (int i = 0; i < n; i++) {
      int index = (i + k) % n;
      nums[index] = temp[i];
    }
  }
};
// @lc code=end

