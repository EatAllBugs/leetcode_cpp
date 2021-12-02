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
299. 猜数字游戏
你在和朋友一起玩 猜数字（Bulls and Cows）游戏，该游戏规则如下：

你写出一个秘密数字，并请朋友猜这个数字是多少。
朋友每猜测一次，你就会给他一个提示，告诉他的猜测数字中有多少位属于数字和确切位置都猜对了（称为“Bulls”, 公牛），有多少位属于数字猜对了但是位置不对（称为“Cows”, 奶牛）。
朋友根据提示继续猜，直到猜出秘密数字。
请写出一个根据秘密数字和朋友的猜测数返回提示的函数，返回字符串的格式为 xAyB ，x 和 y 都是数字，A 表示公牛，用 B 表示奶牛。

xA 表示有 x 位数字出现在秘密数字中，且位置都与秘密数字一致。
yB 表示有 y 位数字出现在秘密数字中，但位置与秘密数字不一致。
请注意秘密数字和朋友的猜测数都可能含有重复数字，每位数字只能统计一次。

 示例 1:
输入: secret = "1807", guess = "7810"
输出: "1A3B"
解释: 1 公牛和 3 奶牛。公牛是 8，奶牛是 0, 1 和 7。
示例 2:

输入: secret = "1123", guess = "0111"
输出: "1A1B"
解释: 朋友猜测数中的第一个 1 是公牛，第二个或第三个 1 可被视为奶牛。
*/

class Solution {
 public:
  string getHint(string secret, string guess) {
    vector<int> stand(10, 0);
    int Rnums = 0, RRnums = 0;
    for (int i = 0; i < secret.size(); i++) {
      stand[secret[i] - '0']++;                    // 统计每个数字出现的次数
    }
    for (int i = 0; i < guess.size(); i++) {
      if (guess[i] == secret[i]) {
        RRnums++;                               // 步骤二
      }
      if (stand[guess[i] - '0'] > 0) {            // 如果这个数字出现了，则已有数量减一
        Rnums++;                                // 步骤一
        stand[guess[i] - '0']--;
      }
    }
    Rnums = Rnums - RRnums;
    string res = to_string(RRnums) + "A" + to_string(Rnums) + "B";
    return res;
  }
};

int main() {
  string secret = "1122";
  string guess = "1222";
  Solution app;
  string ans = app.getHint(secret, guess);
  cout << ans << endl;
  return 0;
}

class Solution {
 public:
  int numOfStrings(vector<string> &patterns, string word) {
    int ans = 0;
    for (auto s : patterns) {
      if (word.find(s) != npos) {
        ans++;
      }
    }
    return ans;
  }
};

class Solution {
 public:
  vector<int> rearrangeArray(vector<int> &nums) {
    int n = nums.size();
    int i = 1;
    while (i < n - 1) {
      int tmp = nums[i - 1] + nums[i + 1];
      if (nums[i] * 2 == tmp) {
        swap(nums[i], nums[i + 1]);
        if (i > 1) {
          i -= 1;
        }
      } else {
        i += 1;
      }
    }
    return nums;
  }
};

class Solution {
 public:
  string makeFancyString(string s) {
    string ans = "";
    ans += s[0];
    int j = 1;
    for (int i = 1; i < s.size(); i++) {
      if (j <= 2 && s[i] == ans[ans.size() - 1]) {
        j++;
        ans += s[i];
      } else if (j > 2) {
        continue;
      } else if (s[i] != ans[ans.size() - 1]) {
        j = 1;
        ans += s[i];
      }
    }
    return ans;
  }
};

/*

词频统计

*/
class Solution {
 public:
  bool reorderedPowerOf2(int n) {
    vector<int> record(10, 0);
    string ori = to_string(n);
    for(auto c : ori){
      record[c - '0']++;
    }
    for (int i = 1; i < 1e9; i * = 2) {
      string s = to_string(i);
      vector<int> str_map(10, 0);
      for (auto a : s) {
        str_map[a - '0']++
      }
      if (str_map == record) {
        return true;
      }
    }
    return false;
  }
};