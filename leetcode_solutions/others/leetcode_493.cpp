#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
#include<numeric>
#include<unordered_set>
#include<cmath>
using namespace std;
/*
给定一个数组 nums ，如果 i < j 且 nums[i] > 2*nums[j] 我们就将 (i, j) 称作一个重要翻转对。
你需要返回给定数组中的重要翻转对的数量。
示例 1:
输入: [1,3,2,3,1]
输出: 2

示例 2:
输入: [2,4,3,5,1]
输出: 3
注意:
给定数组的长度不会超过50000。
输入数组中的所有数字都在32位整数的表示范围内。
*/

class Solution {
 public:
  int reversePairs(vector<int> &nums) {
  }
};

int main() {
  int g = 10000000;
  Solution app;
  vector<int> ans = app.constructRectangle(g);
  cout << ans[0] << endl;
  cout << ans[1] << endl;
  return 0;
}