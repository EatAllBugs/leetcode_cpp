#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
#include<numeric>
#include<unordered_set>
#include<cmath>
using namespace std;
/*
输入: [5, 4, 3, 2, 1]
输出: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
解释: 前三名运动员的成绩为前三高的，因此将会分别被授予 “金牌”，
“银牌”和“铜牌” ("Gold Medal", "Silver Medal" and "Bronze Medal").
余下的两名运动员，我们只需要通过他们的成绩计算将其相对名次即可。

*/

class Solution {
 public:
  vector<string> findRelativeRanks(vector<int> &score) {
    vector<int> order = score;
    sort(order.begin(), order.end());
    reverse(order.begin(), order.end());
    for (int i = 0; i < score.size(); i++) {
    }
  }
};

int main() {
  vector<int> n = {5, 4, 3, 2, 1};
  Solution app;
  vector<string> ans = app.findRelativeRanks(n);
  cout << ans << endl;
  return 0;
}
1 2 4 7 14
class Solution {
 public:
  bool checkPerfectNumber(int num) {
    int ans = 0;
    for (int i = 1; i < sqrt(num) + 1; i++) {
      if (num % i == 0) {
        ans += i;
        if (i != 1) {
          ans += num / i;
        }
      }
    }
    return ans == num;
  }
};