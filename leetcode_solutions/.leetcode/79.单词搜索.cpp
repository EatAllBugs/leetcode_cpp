/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
class Solution {
 public:
  bool dfs(vector<vector<char>> &board, string &word,
    int size, int x, int y, vector<vector<int>> &flag) {
    if (size == word.size()) {
      return true;
    }
    if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] != word[size]) {
      return false;
    }
    if (flag[x][y] == 0) {
      flag[x][y] = 1;
      if (dfs(board, word, size + 1, x + 1, y, flag)
        || dfs(board, word, size + 1, x - 1, y, flag)
        || dfs(board, word, size + 1, x, y + 1, flag)
        || dfs(board, word, size + 1, x, y - 1, flag)) {
        return true;
      }
      flag[x][y] = 0;
    }
    return false;
  }
  bool exist(vector<vector<char>> &board, string word) {
    if (board.empty() || word.empty()) {
      return false;
    }
    int m = board.size(), n = board[0].size();
    vector<vector<int>> flag(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (dfs(board, word, 0, i, j, flag)) {
          return true;
        }
      }
    }
    return false;
  }
};
// @lc code=end

