/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 */

// @lc code=start
class Solution {
 public:
  int maximalSquare(vector<vector<char>> &matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<int> dp(m + 1, vector<int>(n + 1, 0));
    matrix[0][0] = 1;
    int max = 0;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(matrix[i - 1][j - 1] == '1'){
                
            }
        }
    }
  }
};
// @lc code=end

