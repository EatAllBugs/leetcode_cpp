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
给定一种规律 pattern 和一个字符串 str ，判断 str 是否遵循相同的规律。

这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 str 中的
每个非空单词之间存在着双向连接的对应规律。

输入: pattern = "abba", str = "dog cat cat dog"
输出: true
*/

class Solution {
 public:
  bool wordPattern(string pattern, string s) {
    vector<string> temp;
    string res;
    stringstream trans;
    trans.str(s);
    while (trans >> res) {
      temp.push_back(res);
    }
    unordered_map<char, string> ctos;
    unordered_map<string, char> stoc;
    int m = pattern.size();
    int n = temp.size();
    if (m != n) {
      return false;
    }
    for (int i = 0; i < n; i++) {
        char x = pattern[i];
        string y = temp[i];
        if(ctos.count(x) && ctos[x] != y || stoc.count(y) && stoc[y] != x){
            return false;
        }
        ctos[x] = y;
        stoc[y] = x;
    }
    return true;
  }
};

int main() {
  string pattern = "abba";
  string str = "dog cat cat dos";
  Solution app;
  bool ans = app.wordPattern(pattern, str);
  cout << ans << endl;
  return 0;
}