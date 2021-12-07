/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */

// @lc code=start
/**
    上楼梯的复杂版？
    如果连续的两位数符合条件，就相当于一个上楼梯的题目，可以有两种选法：
        1.一位数决定一个字母
        2.两位数决定一个字母
        就相当于dp(i) = dp[i-1] + dp[i-2];
    如果不符合条件，又有两种情况
        1.当前数字是0：
            不好意思，这阶楼梯不能单独走，
            dp[i] = dp[i-2]
        2.当前数字不是0
            不好意思，这阶楼梯太宽，走两步容易扯着步子，只能一个一个走
            dp[i] = dp[i-1];

*/

class Solution {
 public:
  int numDecodings(string s) {
    int length = s.length();
    if (length == 0) {
      return 0;
    }
    if (s[0] == '0') {
      return 0;
    }
    vector<int> dp(length + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < length; i++) {
      dp[i + 1] = s[i] == '0' ? 0 :  dp[i];
      if (i > 0 && (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6'))) {
        dp[i + 1] += dp[i - 1];
      }
    }
    return dp[length];
  }
};

// @lc code=end

