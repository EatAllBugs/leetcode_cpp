#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
/*
给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。
你可以按 任何顺序 返回答案。
示例 1：
输入：n = 4, k = 2
输出：
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
示例 2：
输入：n = 1, k = 1
输出：[[1]]

提示：
1 <= n <= 20
1 <= k <= n
*/

class Solution {
public:
    std::vector<std::vector<int> > result;
    std::vector<int> path;
    void backTracking(int n, int k, int startindex){
      if(path.size() == k){
        result.push_back(path);
        return;
      }
      int index = n - (k - path.size()) + 1;
      for(int i = startindex; i <= index; i++){
        path.push_back(i);
        backTracking(n, k, i + 1);
        path.pop_back();
      }
    }
    std::vector<std::vector<int> > combine(int n, int k) {
      backTracking(n, k ,1);
      return result;
    }
};

int main() {
  int n = 4, k = 2;
  Solution app;
  std::vector<std::vector<int> > ans = app.combine(n , k);
  std::cout<< ans[0].size() << std::endl;
  return 0;
}