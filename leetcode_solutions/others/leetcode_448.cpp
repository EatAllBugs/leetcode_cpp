#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
#include<numeric>
#include<unordered_set>
#include<cmath>
using namespace std;
/*
给你一个含 n 个整数的数组 nums ，其中 nums[i] 在区间 [1, n] 内。
请你找出所有在 [1, n] 范围内但没有出现在 nums 中的数字，并以数组的形式返回结果。
nums = [4,3,2,7,8,2,3,1]
输出：[5,6]
*/

class Solution {
 public:
  vector<int> findDisappearedNumbers(vector<int> nums) {
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++) {
      nums[abs(nums[i]) - 1] = -abs(nums[abs(nums[i]) - 1]);
    }
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] > 0) {
        ans.push_back(i + 1);
      }
    }
    return ans;
  }
  bool isSelfCrossing(vector<int> &distance) {
    if (distance[2] <= distance[0] && distance[3] >= distance[1]) {
      return true;
    }
    return false;
  }
};

int main() {
  vector<int> g = {1,1,1,1};
  Solution app;
  bool ans = app.isSelfCrossing(g);
  cout << ans << endl;
  return 0;
}