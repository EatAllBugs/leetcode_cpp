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
  vector<string> findRelativeRanks(vector<int> &score) {
    int n = score.size();
    vector<string> res(score.size());
    vector<int> order;
    for(int i = 0; i < n; i++){
        order.push_back(i);
    }
    sort(order.begin(), order.end(), [&score](const int &a, const int &b) {
      return score[a] > score[b];
    });
    for (int i = 0; i < n; i++) {
      switch (i) {
        case 0:
          res[order[i]] = "Gold Medal";
          break;
        case 1:
          res[order[i]] = "Silver Medal";
          break;
        case 2:
          res[order[i]] = "Bronze Medal";
          break;
        default:
          res[order[i]] = to_string(i + 1);
          break;
      }
    }
    return res;
  }
};

int main() {
  int n = 101;
  vector<int> num = {1, 2, 3, 4, 5};
  Solution app;
  vector<string> ans = app.findRelativeRanks(num);
  cout << ans.size() << endl;
  return 0;
}