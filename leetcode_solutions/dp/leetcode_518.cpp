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

给你一个整数数组 coins 表示不同面额的硬币，另给一个整数 amount 表示总金额。

请你计算并返回可以凑成总金额的硬币组合数。如果任何硬币组合都无法凑出总金额，返回 0 。

假设每一种面额的硬币有无限个。 

题目数据保证结果符合 32 位带符号整数。

*/

class Solution {
 public:
  int change(int amount, vector<int> &coins) {
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < coins.size(); i++) {
      for (int j = coins[i]; j <= amount; j++) {
        dp[j] += dp[j - coins[i]];
      }
    }
    return dp[amount];
  }
};

int main() {
  int n = 5;
  vector<int> num = {1, 2, 3, 4, 5};
  string s = "sascacamca";
  Solution app;
  int ans = app.change(n, num);
  cout << ans << endl;
  return 0;
}