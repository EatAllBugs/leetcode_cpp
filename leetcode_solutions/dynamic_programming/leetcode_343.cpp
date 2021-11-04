#include<iostream>
#include<vector>
#include<string>
#include<limits.h>
#include<algorithm>
#include<numeric>
#include<unordered_set>
#include<unordered_map>
#include<cmath>
using namespace std;
/*
给定一个正整数 n，将其拆分为至少两个正整数的和，并使这些整数的乘积最大化。 返回你可以获得的最大乘积。

示例 1:

输入: 2
输出: 1
解释: 2 = 1 + 1, 1 × 1 = 1。
示例 2:

输入: 10
输出: 36
解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。
说明: 你可以假设 n 不小于 2 且不大于 58。
*/

class Solution {
 public:
  int integerBreak(int n) {
    vector<int> dp(n + 1);
    dp[2] = 1;
    for (int i = 3; i <= n; i++) {
      for (int j = 1; j < i; j++) {
        dp[i] = max(dp[i], max((i - j) * j, dp[i - j] * j));
        //cout << dp[i] << endl;
      }
    }
    return dp[n];
  }
};
int main() {
  int n = 10;
  vector<int> num = {1, 2, 3, 4, 5};
  string s = "sascacamca";
  Solution app;
  int ans = app.integerBreak(n);
  cout << ans << endl;
  return 0;
}