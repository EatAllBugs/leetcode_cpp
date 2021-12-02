#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
#include<numeric>
using namespace std;
/*
给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。
解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。

示例 1：

输入：nums = [1,2,2]
输出：[[],[1],[1,2],[1,2,2],[2],[2,2]]

示例 2：
输入：nums = [0]
输出：[[],[0]]
*/

class Solution {
public:
    vector<vector<int> > result;
    vector<int> path;
    void backTracking(vector<int> nums, int startindex, vector<bool> visited){
      for(int i = startindex; i < nums.size(); i++){
        if(i > 0 && nums[i] == nums[i - 1] && !visited[i-1]){
          continue;
        }
        path.push_back(nums[i]);
        visited[i] = true;
        result.push_back(path);
        backTracking(nums, i + 1, visited);
        visited[i] = false;
        path.pop_back();
      }
    }
    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
      sort(nums.begin(), nums.end());
      vector<bool> visited(nums.size(), false);
      backTracking(nums, 0, visited);
      result.push_back(vector<int> ());
      return result;
    }
};

int main() {
  vector<int> nums = {1, 2, 3, 4, 5};
  Solution app;
  vector<vector<int> > ans = app.subsetsWithDup(nums);
  for (vector<vector<int> >::iterator it = ans.begin(); it != ans.end(); it++) {
    for (vector<int>::iterator itit = (*it).begin(); itit != (*it).end(); itit++) {
      cout << *itit << endl;
    }
  }
  return 0;
}