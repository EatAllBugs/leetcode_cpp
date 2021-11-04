#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
#include<numeric>
#include<unordered_set>
#include<cmath>
using namespace std;
/*
给定一个整数 num，将其转化为 7 进制，并以字符串形式输出。


*/

class Solution {
 public:
  string convertToBase7(int num) {
    if (num == 0) {
      return to_string(0);
    }
    int temp = abs(num);
    string ans;
    while (temp) {
      ans += to_string(temp % 7);
      temp /= 7;
    }
    if (num < 0) {
      ans += '-';
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};

int main() {
  int n = 101;
  Solution app;
  string ans = app.convertToBase7(n);
  cout << ans << endl;
  return 0;
}