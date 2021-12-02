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

编写一个程序，通过填充空格来解决数独问题。

数独的解法需 遵循如下规则：

数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图）
数独部分空格内已填入了数字，空白格用 '.' 表示。
*/

class Solution {
 private:
  bool backtracking(vector<vector<char> > &board) {
    for (int i = 0; i < board.size(); i++) {        // 遍历行
      for (int j = 0; j < board[0].size(); j++) { // 遍历列
        if (board[i][j] != '.') {
          continue;
        }
        for (char k = '1'; k <= '9'; k++) {     // (i, j) 这个位置放k是否合适
          if (isValid(i, j, k, board)) {
            board[i][j] = k;                // 放置k
            if (backtracking(board)) {
              return true;  // 如果找到合适一组立刻返回
            }
            board[i][j] = '.';              // 回溯，撤销k
          }
        }
        return false;                           // 9个数都试完了，都不行，那么就返回false
      }
    }
    return true; // 遍历完没有返回false，说明找到了合适棋盘位置了
  }
  bool isValid(int row, int col, char val, vector<vector<char>> &board) {
    for (int i = 0; i < 9; i++) { // 判断行里是否重复
      if (board[row][i] == val) {
        return false;
      }
    }
    for (int j = 0; j < 9; j++) { // 判断列里是否重复
      if (board[j][col] == val) {
        return false;
      }
    }
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;
    for (int i = startRow; i < startRow + 3; i++) { // 判断9方格里是否重复
      for (int j = startCol; j < startCol + 3; j++) {
        if (board[i][j] == val) {
          return false;
        }
      }
    }
    return true;
  }
 public:
  void solveSudoku(vector<vector<char>> &board) {
    backtracking(board);
  }
};

int main() {
  int n = 101;
  vector<int> num = {1, 2, 3, 4, 5};
  string s = "sascacamca";
  Solution app;
  string ans = app.isValidSudoku(n);
  cout << ans << endl;
  return 0;
}