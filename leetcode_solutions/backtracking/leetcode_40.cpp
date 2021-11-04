#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
#include<numeric>
/*
给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
candidates 中的每个数字在每个组合中只能使用一次。
注意：解集不能包含重复的组合。 

示例 1:
输入: candidates = [10,1,2,7,6,1,5], target = 8,
输出:
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]

示例 2:
输入: candidates = [2,5,2,1,2], target = 5,
输出:
[
[1,2,2],
[5]
]
*/
using namespace std;
class Solution {
 public:
  vector<vector<int> > result;
  vector<int> path;
  void backTracking(vector<int> nums, int target, int startindex, int sum) {
    if (sum == target) {
      result.push_back(path);
      return;
    }
    for (int i = startindex; i < nums.size() && sum + nums[i] <= target; i++) {
      if (i > startindex && nums[i] == nums[i - 1]) {
        continue;
      }
      sum += nums[i];
      path.push_back(nums[i]);
      backTracking(nums, target, i + 1, sum);
      sum -= nums[i];
      path.pop_back();
    }
  }
  vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
    sort(candidates.begin(), candidates.end());
    backTracking(candidates, target, 0, 0);
    return result;
  }
};
void demo() {
  static int count = 0;
  cout << count << " ";
  count++;
}
int main() {
  vector<int> nums = {2, 5, 2, 1, 2};
  int target = 5;
  const int p = 3;
  const int *const ptr = &p;
  Solution app;
  vector<vector<int> > ans = app.combinationSum2(nums, target);
  cout << p << endl;
  cout << ptr << endl;
  return 0;
}