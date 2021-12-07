/*
 * @lc app=leetcode.cn id=521 lang=cpp
 *
 * [521] 最长特殊序列 Ⅰ
 */

// @lc code=start
/*
简单点来说就是
1.若字符串a和b相同，返回-1
2.若字符串a和b不相同，返回a,b中较长的长度
*/
class Solution {
 public:
  int findLUSlength(string a, string b) {
    if (a == b) {
      return -1;
    }
    return a.size() > b.size() ? a.size() : b.size();
  }
};
// @lc code=end

