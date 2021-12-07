/*
 * @lc app=leetcode.cn id=482 lang=cpp
 *
 * [482] 密钥格式化
 */

// @lc code=start
class Solution {
 public:
  string licenseKeyFormatting(string s, int k) {
    string temp = "";
    for (auto &c : s) {
      if (c == '-') {
        continue;
      }
      temp += c;
    }
    int n = temp.size();
    reverse(temp.begin(), temp.end());
    string ans = "";
    int count = 0;
    for (int i = 0; i < n; i++) {
      count++;
      ans += toupper(temp[i]);
      if (count == k && i != temp.size() - 1) {
        ans += '-';
        count = 0;
      }
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};
// @lc code=end

