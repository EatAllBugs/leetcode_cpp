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

给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。

计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回 -1 。

你可以认为每种硬币的数量是无限的。

 输入：coins = [1, 2, 5], amount = 11
输出：3
解释：11 = 5 + 5 + 1
示例 2：

输入：coins = [2], amount = 3
输出：-1
示例 3：

输入：coins = [1], amount = 0
输出：0
*/

class Solution {
 public:
  int coinChange(vector<int> &coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 0; i < coins.size(); i++) {
      for (int j = coins[i]; j <= amount; j++) {
        if (dp[j - coins[i]] != INT_MAX) {
          dp[j] = min(dp[j - coins[i]] + 1, dp[j]);
        }
      }
    }
    if (dp[amount] == INT_MAX) {
      return -1;
    }
    return dp[amount];
  }
};

int main() {
  int n = 4;
  vector<int> num = {1, 2, 3, 4, 5};
  string s = "sascacamca";
  Solution app;
  int ans = app.coinChange(num, n);
  cout << ans << endl;
  return 0;
}