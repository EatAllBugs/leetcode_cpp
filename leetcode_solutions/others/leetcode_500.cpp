#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
#include<numeric>
#include<unordered_set>
#include<cmath>
using namespace std;
/*
给你一个字符串数组 words ，只返回可以使用在 美式键盘 同一行的字母打印出来的单词。键盘如下图所示。

美式键盘 中：

第一行由字符 "qwertyuiop" 组成。
第二行由字符 "asdfghjkl" 组成。
第三行由字符 "zxcvbnm" 组成。

*/

class Solution {
 public:
  vector<string> findWords(vector<string> &words) {
    string index = "12210111011122000010020202";
    vector<string> ans;
    for (int i = 0; i < words.size(); i++) {
      string tmp = words[i];
      bool flag = true;
      for (int j = 0; j < tmp.size(); j++) {
        //cout << tmp[j] << " " << index[tolower(tmp[j]) - 'a'] << endl;
        if (index[tolower(tmp[j]) - 'a'] != index[tolower(tmp[0]) - 'a']) {
          flag = false;
          break;
        }
      }
      if (flag) {
        ans.push_back(words[i]);
      }
    }
    return ans;
  }
};

int main() {
  vector<string> g = {"Hello", "Alaska", "Dad", "Peace"};
  Solution app;
  vector<string> ans = app.findWords(g);
  cout << ans[0] << endl;
  cout << ans.size() << endl;
  return 0;
}