#include<iostream>
#include<sstream>
#include<vector>
#include<limits.h>
#include<algorithm>
#include<numeric>
#include<unordered_set>
#include<string>
#include<map>
#include<unordered_map>
using namespace std;
/*
你和你的朋友，两个人一起玩 Nim 游戏：

桌子上有一堆石头。
你们轮流进行自己的回合，你作为先手。
每一回合，轮到的人拿掉 1 - 3 块石头。
拿掉最后一块石头的人就是获胜者。
假设你们每一步都是最优解。请编写一个函数，来判断你是否可以在给定石头数量为 n 的情况下赢得游戏。
如果可以赢，返回 true；否则，返回 false 。

*/

class Solution {
 public:
  bool canWinNim(int n) {
    if (n % 4 == 0) {
      return false;
    }
    return true;
  }
};

int main() {
  int n = 10;
  Solution app;
  bool ans = app.canWinNim(n);
  cout << ans << endl;
  return 0;
}