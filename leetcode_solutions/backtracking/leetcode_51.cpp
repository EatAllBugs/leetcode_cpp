#include<iostream>
#include<vector>
#include<string>
#include<limits.h>
#include<algorithm>
#include<numeric>
#include<unordered_set>
#include<unordered_map>
#include<cmath>
#include<ctime>
using namespace std;
/*
n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。

给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。

每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。

*/

class Solution {
 public:
  vector<vector<string> > result;
  // n棋盘大小
  // row 遍历到第几行
  void back_tracking(int n, int row, vector<string> chess_board) {
    if (row == n) {
      result.push_back(chess_board);
      return;
    }
    for (int i = 0; i < n; i++) {
      if (isValid(row, i, chess_board, n)) {
        chess_board[row][i] = 'Q';
        back_tracking(n, row + 1, chess_board);
        chess_board[row][i] = '.';
      }
    }
  }
  bool isValid(int row, int col, vector<string> &chessboard, int n) {
    // 检查列
    for (int i = 0; i < row; i++) { // 这是一个剪枝
      if (chessboard[i][col] == 'Q') {
        return false;
      }
    }
    // 检查 45度角是否有皇后
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
      if (chessboard[i][j] == 'Q') {
        return false;
      }
    }
    // 检查 135度角是否有皇后
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
      if (chessboard[i][j] == 'Q') {
        return false;
      }
    }
    return true;
  }
  vector<vector<string> > solveNQueens(int n) {
    result.clear();
    clock_t start_time, end_time;
    start_time = clock();
    vector<string> chessboard(n, std::string(n, '.'));
    back_tracking(n, 0, chessboard);
    end_time = clock();
    cout << "The run time is: " << (double)(end_time - start_time) / CLOCKS_PER_SEC << "s" << endl;
    return result;
  }

};

int main() {
  int n = 101;
  vector<int> num = {1, 2, 3, 4, 5};
  string s = "sascacamca";
  Solution app;
  vector<vector<string> > ans = app.solveNQueens(20);
  cout << ans.size() <<  " " << ans[0].size() << " " << ans[0][0].size() << endl;
  return 0;
}