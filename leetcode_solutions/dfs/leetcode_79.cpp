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

给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
*/

class Solution {
 public:
  bool dfs(vector<vector<char>> &board, string &word,
    int size, int x, int y, vector<vector<int>> &f) {
    if (size == word.size()) {
      return true;
    }
    //outofbound
    if (x < 0 || x >= board.size()
      || y < 0 || y > board[0].size()
      || board[x][y] != word[size]) {
      return false;
    }
    if (f[x][y] == 0) {
      f[x][y] = 1;
      if (dfs(board, word, size + 1, x + 1, y, f)
        || dfs(board, word, size + 1, x - 1, y, f)
        || dfs(board, word, size + 1, x, y + 1, f)
        || dfs(board, word, size + 1, x, y - 1, f)) {
        return true;
      }
      f[x][y] = 0;
    }
    return false;
  }
  bool exist(vector<vector<char>> &board, string word) {
    if (board.empty() || word.empty()) {
      return false;
    }
    int row = board.size(), col = board[0].size();
    vector<vector<int>> f(row, vector<int>(col, 0));
    for (int i = 0; i < row; ++i) {
      for (int j = 0; j < col; ++j) {
        if (dfs(board, word, 0, i, j, f)) {
          return true;
        }
      }
    }
    return false;
  }
};

class Solution {
 public:
  bool check(vector<vector<char>> &board, vector<vector<int>> &visited, int i, int j, string &s,
    int k) {
    if (board[i][j] != s[k]) {
      return false;
    } else if (k == s.length() - 1) {
      return true;
    }
    visited[i][j] = true;
    vector<pair<int, int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool result = false;
    for (const auto &dir : directions) {
      int newi = i + dir.first, newj = j + dir.second;
      if (newi >= 0 && newi < board.size() && newj >= 0 && newj < board[0].size()) {
        if (!visited[newi][newj]) {
          bool flag = check(board, visited, newi, newj, s, k + 1);
          if (flag) {
            result = true;
            break;
          }
        }
      }
    }
    visited[i][j] = false;
    return result;
  }

  bool exist(vector<vector<char>> &board, string word) {
    int h = board.size(), w = board[0].size();
    vector<vector<int>> visited(h, vector<int>(w));
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        bool flag = check(board, visited, i, j, word, 0);
        if (flag) {
          return true;
        }
      }
    }
    return false;
  }
};

int main() {
  int n = 101;
  vector<int> num = {1, 2, 3, 4, 5};
  Solution app;
  vector<string> ans = app.exist(num);
  cout << ans.size() << endl;
  return 0;
}