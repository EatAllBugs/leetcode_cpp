/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
class Solution {
 public:
//   bool wordBreak(string s, vector<string> &wordDict) {
//     vector<bool> dp(s.size() + 1, false);
//     unordered_set<string> m(wordDict.begin(), wordDict.end());
//     dp[0] = true;
//     for (int i = 1; i <= s.size(); ++i) {
//       for (int j = 0; j < i; ++j) {
//         if (dp[j] && m.find(s.substr(j, i - j)) != m.end()) {
//           dp[i] = true;
//           break;
//         }
//       }
//     }
//     return dp[s.size()];
//   }
  bool wordBreak(string s, vector<string> &wordDict) {
    vector<bool> dp(s.size() + 1, false);
    unordered_set<string> m(wordDict.begin(), wordDict.end());
    dp[0] = true;
    //获取最长字符串长度
    int maxWordLength = 0;
    for (int i = 0; i < wordDict.size(); ++i) {
      maxWordLength = std::max(maxWordLength, (int)wordDict[i].size());
    }
    for (int i = 1; i <= s.size(); ++i) {
      for (int j = std::max(i - maxWordLength, 0); j < i; ++j) {
        if (dp[j] && m.find(s.substr(j, i - j)) != m.end()) {
          dp[i] = true;
          break;
        }
      }
    }
    return dp[s.size()];
  }
};
// @lc code=end

