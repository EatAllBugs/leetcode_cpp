#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
#include<numeric>
using namespace std;
/*
给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。
示例 1：

输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
示例 2：

输入：nums = [0,1]
输出：[[0,1],[1,0]]
示例 3：

输入：nums = [1]
输出：[[1]]
*/

class Solution {
 public:
  vector<vector<int> > result;
  vector<int> path;
  void backTracking(vector<int> nums, vector<bool> used) {
    if (path.size() == nums.size()) {
      result.push_back(path);
    }
    for (int i = 0; i < nums.size(); i++) {
      if(used[i]){
        continue;
      }
      path.push_back(nums[i]);
      used[i] = true;
      backTracking(nums, used);
      path.pop_back();
      used[i] = false;
    }
  }
  vector<vector<int> > permute(vector<int> &nums) {
    vector<bool> used(nums.size(), false);
    backTracking(nums, used);
    return result;
  }
};

int main() {
  vector<int> nums = {1, 2, 3, 4, 5};
  Solution app;
  vector<vector<int> > ans = app.permute(nums);
  return 0;
}