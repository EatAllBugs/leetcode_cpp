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

给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水.
输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
输出：6
解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1]
表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。

*/

class Solution {
 public:
  int trap(vector<int> &height) {
    int sum = 0;
    int n = height.size();
    for (int i  = 1; i < n - 1; i++) {
      // if (i == 0 || i == n - 1) {
      //   continue;
      // }
      int left = height[i];
      int right = height[i];
      for (int j = i + 1; j < n; j++) {
        left = max(height[j], left);
      }
      for (int j = i - 1; j >= 0; j--) {
        right = max(height[j], right);
      }
      int h = min(left, right) - height[i];
      sum += h > 0 ? h : 0;
    }
    return sum;
  }
};

int main() {
  int n = 101;
  vector<int> num = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  string s = "sascacamca";
  Solution app;
  int ans = app.trap(num);
  cout << ans << endl;
  return 0;
}