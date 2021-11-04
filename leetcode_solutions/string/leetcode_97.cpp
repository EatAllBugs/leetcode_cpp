#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
#include<numeric>
#include<unordered_set>
#include<map>
using namespace std;
/*
给定三个字符串 s1、s2、s3，请你帮忙验证 s3 是否是由 s1 和 s2 交错 组成的。

两个字符串 s 和 t 交错 的定义与过程如下，其中每个字符串都会被分割成若干 非空 子字符串：

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
交错 是 s1 + t1 + s2 + t2 + s3 + t3 + ... 
或者 t1 + s1 + t2 + s2 + t3 + s3 + ...
提示：a + b 意味着字符串 a 和 b 连接。
*/

class Solution {
 public:
  bool isInterleave(string s1, string s2, string s3) {
    if (s1.size() + s2.size() !=  s3.size()) {
      return false;
    }
    if (s1.size() == 0 && s3 != s2) {
      return false;
    }
    if (s2.size() == 0 && s3 != s1) {
      return false;
    }
    int i = 0, j = 0, k = 0;
    while (i < s1.size() && j < s2.size() && k < s3.size()) {
      if (s3[k] == s1[i] && s3[k] == s2[j]) {
        i++;
        k++;
      } else if (s3[k] == s1[i] && s3[k] != s2[j]) {
        i++;
        k++;
      } else if (s3[k] != s1[i] && s3[k] == s2[j]) {
        j++;
        k++;
      } else if (s3[k] != s1[i] && s3[k] != s2[j]) {
        return false;
      }
    }
    return true;
  }
};

int main() {
  vector<string> g = {"eat", "tea", "tan", "ate", "nat", "bat"};
  Solution app;
  vector<vector<string> > ans = app.isInterleave(g);
  cout << ans.size() << endl;
  return 0;
}