/*
 * @lc app=leetcode.cn id=289 lang=cpp
 *
 * [289] 生命游戏
 */

// @lc code=start
class Solution {
 public:
  int m = 0, n = 0;
  void gameOfLife(vector<vector<int>> &board) {
    m = board.size();
    n = board[0].size();
    vector<int> temp(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        temp[i][j] = getNum(board, i, j);
      }
    }
    board = temp;
  }
  int getNum(vector<vector<int>> &board, int x, int y) {
    int m = bo
  }
};
// @lc code=end

