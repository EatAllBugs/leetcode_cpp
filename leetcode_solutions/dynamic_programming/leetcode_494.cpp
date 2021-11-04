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

给你一个整数数组 nums 和一个整数 target 。

向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ：

例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，
然后串联起来得到表达式 "+2-1" 。
返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。

*/

class Solution {
 public:
  int findTargetSumWays(vector<int> &nums, int target) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if ((sum + target) % 2 == 1) {
      return 0;
    }
    if (abs(target) > sum) {
      return 0;
    }
    int bagsize = (sum + target) / 2;
    vector<int> dp(bagsize + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < nums.size(); i++) {
      for (int j = bagsize; j >= nums[i]; j--) {
        dp[j] += dp[j - nums[i]];
      }
    }
    return dp[bagsize];
  }
};

int main() {
  int n = 4;
  vector<int> num = {1, 1, 1, 1, 1, 1};
  string s = "sascacamca";
  Solution app;
  int ans = app.findTargetSumWays(num, n);
  cout << ans << endl;
  return 0;
}