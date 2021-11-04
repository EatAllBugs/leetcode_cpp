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

给你一个由 不同 整数组成的数组 nums ，和一个目标整数 target 。
请你从 nums 中找出并返回总和为 target 的元素组合的个数。

输入：nums = [1,2,3], target = 4
输出：7
解释：
所有可能的组合为：
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
请注意，顺序不同的序列被视作不同的组合。


*/

class Solution {
 public:
  int combinationSum4(vector<int> &nums, int target) {
    vector<int> dp(target + 1, 0);
    dp[0] = 1;
    for (int i = 0; i <= target; i++) {
      for (int j = 0; j < nums.size(); j++) {
        // if (i >= nums[j] && dp[i] < INT_MAX - dp[i - nums[j]]) {
        //
        // }
        if (i >= nums[j]) {
          dp[i] += dp[i - nums[j]];
        }
      }
    }
    return dp[target];
  }
};
int main() {
  int n = 4;
  vector<int> num = {1, 2, 3};
  string s = "sascacamca";
  Solution app;
  int ans = app.combinationSum4(num, n);
  cout << ans << endl;
  return 0;
}