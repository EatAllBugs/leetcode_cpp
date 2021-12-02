#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
/*
找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。

说明：

所有数字都是正整数。
解集不能包含重复的组合。 
示例 1:

输入: k = 3, n = 7
输出: [[1,2,4]]
示例 2:

输入: k = 3, n = 9
输出: [[1,2,6], [1,3,5], [2,3,4]]
*/

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {

    }
};

int main() {
  int n = 4, k = 2;
  Solution app;
  std::vector<std::vector<int> > ans = app.combine(n , k);
  std::cout<< ans.size() << std::endl;
  return 0;
}