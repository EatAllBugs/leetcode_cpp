/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 */

// @lc code=start
class NumArray {
 public:
  vector<int> nums;
  vector<int> sums;
  NumArray(vector<int> &nums) {
    this->nums = nums;
    getSums(nums);
  }
  void getSums(vector<int> &nums) {
    sums.resize(nums.size());
    for (int i = 0; i < nums.size(); i++) {
      int sum = 0;
      for (int j = 0; j < i; j++) {
        sum += nums[j];
      }
      sums[i] = sum;
    }
  }

  int sumRange(int left, int right) {
    return sums[right] - sums[left] + nums[right];
  }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end

