#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
#include<numeric>
#include<unordered_set>
using namespace std;
/*
给你一个整数数组 nums ，找出并返回所有该数组中不同的递增子序列，递增子序列中 至少有两个元素 。
你可以按任意顺序返回答案。

数组中可能含有重复元素，如出现两个整数相等，也可以视作递增序列的一种特殊情况。

示例 1：
输入：nums = [4,6,7,7]
输出：[[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]
示例 2：

输入：nums = [4,4,3,2,1]
输出：[[4,4]]
*/

class Solution {
 private:
  vector<vector<int> > result;
  vector<int> path;
  void backtracking(vector<int> &nums, int startIndex) {
    if (path.size() > 1) {
      result.push_back(path);
    }
    int used[201] = {0}; // 这里使用数组来进行去重操作，题目说数值范围[-100, 100]
    for (int i = startIndex; i < nums.size(); i++) {
      if ((!path.empty() && nums[i] < path.back())
        || used[nums[i] + 100] == 1) {
        continue;
      }
      used[nums[i] + 100] = 1; // 记录这个元素在本层用过了，本层后面不能再用了
      path.push_back(nums[i]);
      backtracking(nums, i + 1);
      path.pop_back();
    }
  }
 public:
  vector<vector<int> > findSubsequences(vector<int> &nums) {
    result.clear();
    path.clear();
    backtracking(nums, 0);
    return result;
  }
};

int main() {
  vector<int> nums = {1, 2, 3, 4, 5};
  Solution app;
  vector<vector<int> > ans = app.findSubsequences(nums);
  for (vector<vector<int> >::iterator it = ans.begin(); it != ans.end(); it++) {
    for (vector<int>::iterator itit = (*it).begin(); itit != (*it).end(); itit++) {
      cout << *itit << endl;
    }
  }
  return 0;
}