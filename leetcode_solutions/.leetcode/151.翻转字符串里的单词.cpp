/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 翻转字符串里的单词
 */

// 先切割 后反转
// @lc code=start
class Solution {
 public:
  string reverseWords(string s) {
    vector<string> words;
    string res;
    stringstream trans;
    trans.str(s);
    while (trans >> res) {
      words.push_back(res);
    }
    string ans;
    cout << words.size() << endl;
    for (int i = words.size() - 1; i >= 0; i--) {
      ans += words[i];
      if (i != 0) {
        ans += " ";
      }
    }
    return ans;
  }
};
// @lc code=end

