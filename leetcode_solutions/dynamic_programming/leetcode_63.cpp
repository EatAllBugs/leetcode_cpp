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

一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。

问总共有多少条不同的路径？

*/

class Solution {
 public:
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<int> dp(m, vector<int>(n, 0));
    for (int i = 0; i < m && obstacleGrid[i][0] == 0; i++) {
      dp[i][0] = 1;
    }
    for (int j = 0; j < n && obstacleGrid[0][j] == 0; j++) {
      dp[0][j] = 1;
    }
    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        if (obstacleGrid[i][j] == 0) {
          dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
      }
    }
    return dp[m - 1][n - 1];
  }
};

int main() {
  int m = 3;
  int n = 7;
  vector<int> num = {1, 2, 3, 4, 5};
  string s = "sascacamca";
  Solution app;
  int ans = app.uniquePaths(m, n);
  cout << ans << endl;
  return 0;
}