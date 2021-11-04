#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
#include<numeric>
#include<unordered_set>
using namespace std;
/*
给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

示例: 输入: [-2,1,-3,4,-1,2,1,-5,4] 
输出: 6 
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
      int result = INT_MIN;
      int count = 0;
      for(int i = 0; i < nums.size(); i++){
        count += nums[i];
        result = max(result, count);
        if(count < 0){
          count = 0;
        }
      }
      return count;
    }
};

int main() {
  vector<int> g = {1, 2,-1,6,7,9};
  Solution app;
  int ans = app.maxSubArray(g);
  cout << ans << endl;
  return 0;
}