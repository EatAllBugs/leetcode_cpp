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

请你判断一个 9x9 的数独是否有效。只需要 根据以下规则 ，验证已经填入的数字是否有效即可。

数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图）
数独部分空格内已填入了数字，空白格用 '.' 表示。

注意：

一个有效的数独（部分已被填充）不一定是可解的。
只需要根据以上规则，验证已经填入的数字是否有效即可
*/

class Solution {
 public:
  bool isValidSudoku(vector<vector<char> > &board) {
    vector<vector<bool> >  row(9, vector<bool>(9, false));
    vector<vector<bool> > col(row);
    vector<vector<bool> > square(row);
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        if (board[i][j] == '.') {
          continue;
        }
        int num = board[i][j] - '1';
        int block = i / 3 * 3 + j / 3;
        if (row[i][num] || col[j][num] || square[block][num]) {
          return false;
        } else {
          row[i][num] = true;
          col[j][num] = true;
          square[block][num] = true;
        }
      }
    }
    return true;
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