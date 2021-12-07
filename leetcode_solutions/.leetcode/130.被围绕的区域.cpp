/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

// @lc code=start

// 把边界的'O'变成‘1’，然后遍历，遇见‘1’恢复成‘O’，其余都变成'X'
class Solution {
 public:
  void solve(vector<vector<char>> &board) {
    int m = board.size(), n = board[0].size();
    for (int i = 0; i < m; i++) {
      dfs(board, i, 0);
      dfs(board, i, n - 1);
    }
    for (int i = 1; i < n - 1; i++) {
      dfs(board, 0, i);
      dfs(board, m - 1, i);
    }
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (board[i][j] == '1') {
          board[i][j] = 'O';
        } else if (board[i][j] == 'O') {
          board[i][j] = 'X';
        }
      }
    }
  }

  void dfs(vector<vector<char>> &board, int x, int y) {
    if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] != 'O') {
      return;
    }
    board[x][y] = '1';
    dfs(board, x + 1, y);
    dfs(board, x - 1, y);
    dfs(board, x, y + 1);
    dfs(board, x, y - 1);
  }
};
// @lc code=end

