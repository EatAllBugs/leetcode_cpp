/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
/*
窗口就是 满足其和 ≥ s 的长度最小的 连续 子数组。

窗口的起始位置如何移动：如果当前窗口的值大于s了，窗口就要向前移动了（也就是该缩小了）。

窗口的结束位置如何移动：窗口的结束位置就是遍历数组的指针，窗口的起始位置设置为数组的起始位置就可以了。

*/
class Solution {
 public:
  int minSubArrayLen(int target, std::vector<int> &nums) {
    int n = nums.size();
    int i = 0;
    int sublength = 0;
    int sum = 0;
    int result = __INT32_MAX__;
    for (int j = 0; j < n; j++) {
      sum += nums[j];
      while (sum >= target) {
        sublength = j - i + 1;
        result = sublength < result ? sublength : result;
        sum -= nums[i];
        i++;
      }
    }
    result = result == __INT32_MAX__ ? 0 : result;
    return result;
  }
};
// @lc code=end

