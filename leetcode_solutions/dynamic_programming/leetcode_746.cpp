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

[1, 100, 1, 1, 1, 100, 1, 1, 100, 1]


*/

class Solution {
 public:
  int minCostClimbingStairs(vector<int> &cost) {
    if (cost.size() <= 1) {
      return cost[cost.size() - 1];
    }
    vector<int> dp(2);
    dp[0] = cost[0];
    dp[1] = cost[1];
    for (int i = 2; i < cost.size(); i++) {
      int temp = min(dp[0], dp[1]) + cost[i];
      dp[0] = dp[1];
      dp[1] = temp;
    }
    return min(dp[0], dp[1]);
  }
};

int main() {
  int n = 101;
  vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
  string s = "sascacamca";
  Solution app;
  int ans = app.minCostClimbingStairs(cost);
  cout << ans << endl;
  return 0;
}