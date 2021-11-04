#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
#include<numeric>
#include<unordered_set>
using namespace std;
/*
给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。

你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要 使用另一个矩阵来旋转图像。
*/

class Solution {
 public:
  void rotate(vector<vector<int> > &matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
      for (int j = i ; j < n; j ++) {
        int temp = matrix[i][j];
        matrix[i][j] = matrix[j][i];
        matrix[j][i] = temp;
      }
    }
    for (int i = 0; i < n ; i++) {
      for (int j = 0 ; j < n / 2; j++) {
        int tmp = matrix[i][j];
        matrix[i][j] = matrix[i][n - 1 - j];
        matrix[i][n - 1 - j] = tmp;
      }
    }
  }
};

int main() {
  vector<vector<int> >  g = {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
  Solution app;
  for (int i = 1; i < INT_MAX; i *= 4) {
    cout << i << endl;
  }
  app.rotate(g);
  return 0;
}