/*
 * @lc app=leetcode.cn id=599 lang=cpp
 *
 * [599] 两个列表的最小索引总和
 */

// @lc code=start
class Solution {
 public:
  vector<string> findRestaurant(vector<string> &list1, vector<string> &list2) {
    vector<string> ans;
    int min_num = __INT32_MAX__;
    unordered_map<string, int> bp;
    for (int i = 0; i < list2.size(); i++) {
      bp[list2[i]] = i + 1;
    }
    for (int j = 0; j < list1.size(); j++) {
      if (bp[list1[j]] != 0) {
        int temp_num = j + bp[list1[j]] - 1;
        if (temp_num < min_num) {
          min_num = temp_num;
        }
      }
    }
    for (int j = 0; j < list1.size(); j++) {
      if (bp[list1[j]] != 0) {
        int temp_num = j + bp[list1[j]] - 1;
        if (temp_num == min_num) {
          ans.push_back(list1[j]);
        }
      }
    }
    return ans;
  }
};
// @lc code=end

