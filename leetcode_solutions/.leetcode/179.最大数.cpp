/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
 */

// @lc code=start
class Solution {
 public:
  static bool cmp(const int &a, const int &b) {
    string sa = to_string(a);
    string sb = to_string(b);
    return sa + sb > sb + sa;
  }
  string largestNumber(vector<int> &nums) {
    sort(nums.begin(), nums.end(), cmp);
    string ans = "";
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == 0 && ans[0] == '0') {
        continue;
      }
      ans += to_string(nums[i]);
    }
    return ans;
  }
};
// @lc code=end

