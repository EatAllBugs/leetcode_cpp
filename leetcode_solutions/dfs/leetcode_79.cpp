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
    
    bool exist(vector<vector<char>>& board, string word) {

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