#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
#include<numeric>
using namespace std;
/*
给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。

解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。

示例 1：
输入：nums = [1,2,3]
输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
示例 2：

输入：nums = [0]
输出：[[],[0]]
*/

class Solution {
 public:
  vector<vector<int> > result;
  vector<int> path;
  void backTracking(vector<int> nums, int startindex) {
    for (int i = startindex; i < nums.size(); i++) {
      path.push_back(nums[i]);
      result.push_back(path);
      backTracking(nums, i + 1);
      path.pop_back();
    }
  }
  vector<vector<int> > subsets(vector<int> &nums) {
    backTracking(nums, 0);
    return result;
  }
};

int main() {
  vector<int> nums = {1, 2, 3, 4, 5};
  Solution app;
  vector<vector<int> > ans = app.subsets(nums);
  for (vector<vector<int> >::iterator it = ans.begin(); it != ans.end(); it++) {
    for (vector<int>::iterator itit = (*it).begin(); itit != (*it).end(); itit++) {
      cout << *itit << endl;
    }
  }
  return 0;
}