#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
#include<numeric>
#include<unordered_set>
#include<cmath>
using namespace std;
/*
给定一个单词，你需要判断单词的大写使用是否正确。

我们定义，在以下情况时，单词的大写用法是正确的：

全部字母都是大写，比如"USA"。
单词中所有字母都不是大写，比如"leetcode"。
如果单词不只含有一个字母，只有首字母大写， 比如 "Google"。
否则，我们定义这个单词没有正确使用大写字母。
*/

class Solution {
 public:
  bool detectCapitalUse(string word) {
    int ans = 0;
    for (int i = 0; i < word.size(); i++) {
      if (word[i] == tolower(word[i])) {
        ans++;
      }
    }
    if (ans == word.size() || ans == 0 || (ans == 1 && word[0] != tolower(word[0]))) {
      return true;
    }
    return false;
  }
};

int main() {
  string n = "FlaG";
  Solution app;
  bool ans = app.detectCapitalUse(n);
  cout << ans << endl;
  return 0;
}