#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
#include<numeric>
using namespace std;
/*
给定一个只包含数字的字符串，用以表示一个 IP 地址，返回所有可能从 s 获得的 有效 IP 地址 。
你可以按任何顺序返回答案。

有效IP地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。
例如："0.1.2.201" 和 "192.168.1.1" 是 有效 IP 地址，
但是 "0.011.255.245"、"192.168.1.312" 和 "192.168@1.1" 是 无效 IP 地址。

示例 1：
输入：s = "25525511135"
输出：["255.255.11.135","255.255.111.35"]
示例 2：
输入：s = "0000"
输出：["0.0.0.0"]
示例 3：
输入：s = "1111"
输出：["1.1.1.1"]
示例 4：
输入：s = "010010"
输出：["0.10.0.10","0.100.1.0"]
示例 5：
输入：s = "101023"
输出：["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
*/

class Solution {
 public:
  vector<string> result;
  void backTracking(string s, int startindex, int pointnum) {
    if (pointnum == 3) {
      if (isValid(s, startindex, s.size() - 1)) {
        result.push_back(s);
      }
    }
    for (int i = startindex; i < s.size(); i++) {
      if (isValid(s, startindex, i)) { // 判断 [startIndex,i] 这个区间的子串是否合法
        s.insert(s.begin() + i + 1, '.');   // 在i的后面插入一个逗点
        pointnum++;
        backTracking(s, i + 2, pointnum);   // 插入逗点之后下一个子串的起始位置为i+2
        pointnum--;                         // 回溯
        s.erase(s.begin() + i + 1);         // 回溯删掉逗点
      } else {
        break;  // 不合法，直接结束本层循环
      }
    }
  }
  bool isValid(const string &s, int start, int end) {
    if (start > end) {
      return false;
    }
    if (s[start] == '0' && start != end) {
      return false;
    }
    int num = 0;
    for (int i = start; i <= end; i++) {
      if (s[i] > '9' || s[i] < '0') {
        return false;
      }
      num = num * 10 + (s[i] - '0');
      if (num > 255) {
        return false;
      }
    }
    return true;
  }
  vector<string> restoreIpAddresses(string s) {
    if (s.size() > 12) {
      return result;
    }
    backTracking(s, 0, 0);
    return result;
  }
};

int main() {
  string target = "1111111111";
  Solution app;
  vector<string> ans = app.restoreIpAddresses(target);
  cout << ans[1].size() << endl;
  return 0;
}