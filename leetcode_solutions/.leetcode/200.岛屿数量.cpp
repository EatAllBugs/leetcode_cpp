/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution {
 public:
  int numIslands(vector<vector<char>> &grid) {
    int m = grid.size(), n = grid[0].size();
    int ans = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == '1') {
          infect(grid, i, j);
          ans++;
        }
      }
    }
    return ans;
  }
  void infect(vector<vector<char>> &grid, int x, int y) {
    if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] != '1') {
      return;
    }
    grid[x][y] = '2';
    infect(grid, x + 1, y);
    infect(grid, x - 1, y);
    infect(grid, x, y + 1);
    infect(grid, x, y - 1);
  }

};
// @lc code=end

