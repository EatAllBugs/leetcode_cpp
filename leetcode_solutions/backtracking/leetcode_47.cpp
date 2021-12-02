#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
#include<numeric>
using namespace std;
/*
给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。

 

示例 1：

输入：nums = [1,1,2]
输出：
[[1,1,2],
 [1,2,1],
 [2,1,1]]
示例 2：

输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
*/

class Solution {
 public:
  vector<vector<int> > result;
  vector<int> path;
  void backTracking(vector<int> nums, vector<bool> used) {
    if (path.size() == nums.size()) {
      result.push_back(path);
      return;
    }
    for (int i = 0; i < nums.size(); i++) {
      if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) {
        continue;
      }
      if (!used[i]) {
        path.push_back(nums[i]);
        used[i] = true;
        backTracking(nums, used);
        path.pop_back();
        used[i] = false;
      }
    }
  }
  vector<vector<int> > permuteUnique(vector<int> &nums) {
    vector<bool> used(nums.size(), false);
    sort(nums.begin(), nums.end());
    backTracking(nums, used);
    return result;
  }
};

int main() {
  vector<int> nums = {1, 2, 3, 4, 5};
  Solution app;
  vector<vector<int> > ans = app.permuteUnique(nums);
  return 0;
}