#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
#include<numeric>
#include<unordered_set>
#include<map>
#include<set>
using namespace std;
/*
给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。
字母异位词 是由重新排列源单词的字母得到的一个新单词，所有源单词中的字母都恰好只用一次。

示例 1:
输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
输出: [["bat"],["nat","tan"],["ate","eat","tea"]]

示例 2:
输入: strs = [""]
输出: [[""]]

示例 3:
输入: strs = ["a"]
输出: [["a"]]

提示：
1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] 仅包含小写字母
*/

class Solution {
 public:
  vector<vector<string> > groupAnagrams(vector<string> &strs) {
    map<string, vector<string> > mp;
    vector<vector<string> > result;
    for (int i = 0; i < strs.size(); i++) {
      string str = strs[i];
      sort(str.begin(), str.end());
      if (mp.find(str) == mp.end()) {
        vector<string> item;
        mp[str] = item;
      }
      mp[str].push_back(strs[i]);
    }
    map<string, vector<string> >::iterator it;
    for (it = mp.begin(); it !=  mp.end(); it++) {
      result.push_back((*it).second);
    }
    return result;
  }
};

int main() {
  vector<string> g = {"eat", "tea", "tan", "ate", "nat", "bat"};
  Solution app;
  vector<vector<string> > ans = app.groupAnagrams(g);
  // cout << ans.size() << endl;
  unordered_set<int> tmp;
  for (int i = 1; i < 1e9; i *= 2) {
    tmp.insert(i);
    cout << i << endl;
  }
  return 0;
}