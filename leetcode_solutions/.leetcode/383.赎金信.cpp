/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */

// @lc code=start
class Solution {
 public:
  bool canConstruct(string ransomNote, string magazine) {
      int m = ransomNote.size();
      int n = magazine.size();
      if(m > n){
          return false;
      }
      vector<int> nums(26, 0);
      for(auto &c : magazine){
          nums[c - 'a']++;
      }
      for(auto &c : ransomNote){
          nums[c - 'a']--;
          if(nums[c - 'a'] < 0){
              return false;
          }
      }
      return true;
  }
};
// @lc code=end

