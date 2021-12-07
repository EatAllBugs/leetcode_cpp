/*
 * @lc app=leetcode.cn id=904 lang=cpp
 *
 * [904] 水果成篮
 */

// @lc code=start
// 只有两个元素的最长连续子序列的长度

// [1,2,1,3,4,5,2,3,3,3,3,4,5]
class Solution {
 public:
  int totalFruit(vector<int> &fruits) {
    int slow = 0;
    unordered_map<int, int> buckets;
    int result = 0;
    for (int fast = 0; fast < fruits.size(); fast++) {
      buckets[fruits[fast]]++;
      while (buckets.size() > 2) {
        buckets[fruits[slow]]--;
        if (buckets[fruits[slow]] == 0) {
          buckets.erase(fruits[slow]);
        }
        slow++;
      }
      result = max(fast - slow + 1, result);
    }
    return result;
  }
};
// @lc code=end

