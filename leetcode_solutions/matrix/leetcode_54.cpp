#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
#include<numeric>
#include<unordered_set>
using namespace std;
/*
给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。

输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[1,2,3,6,9,8,7,4,5]
*/

class Solution {
 public:
  vector<int> spiralOrder(vector<vector<int> > &matrix) {
    if (matrix.empty() || matrix[0].empty()) return {};
    vector<int> res;
    int m = matrix.size(), n = matrix[0].size();
    // 确定上下左右四条边的位置
    int up = 0, down = m - 1, left = 0, right = n - 1;
    while (true) {
      for (int i = left; i <= right; i++) {
        res.push_back(matrix[up][i]);
      }
      if (++up > down) {
        break;
      }
      for (int i = up; i <= down; i++) {
        res.push_back(matrix[i][right]);
      }
      if (--right < left) {
        break;
      }
      for (int i = right; i >= left; i--) {
        res.push_back(matrix[down][i]);
      }
      if (--down < up) {
        break;
      }
      for (int i = down; i >= up; i--) {
        res.push_back(matrix[i][left]);
      }
      if (++left > right) {
        break;
      }
    }
    return res;
  }
};

int main() {
  vector<vector<int> >  g = {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
  Solution app;
  vector<int> ans = app.spiralOrder(g);
  cout << ans.size() << endl;
  return 0;
}