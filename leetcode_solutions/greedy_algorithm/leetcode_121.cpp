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




*/

class Solution {
 public:
  int maxProfit(vector<int> &prices) {
    //动态规划
    int low = INT_MAX, res = 0;
    for (int i = 0; i < prices.size(); i++) {
      low = min(low, prices[i]);
      res = max(res, prices[i] - low);
    }
    cout  << low << endl;
    return res;
  }
};

int main() {
  int n = 101;
  vector<int> num = {7, 1, 5, 3, 6, 4};
  string s = "sascacamca";
  Solution app;
  int ans = app.maxProfit(num);
  cout << ans << endl;
  return 0;
}