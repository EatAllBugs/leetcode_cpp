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

给定一个 N 叉树，找到其最大深度。

最大深度是指从根节点到最远叶子节点的最长路径上的节点总数。

N 叉树输入按层序遍历序列化表示，每组子节点由空值分隔（请参见示例）。
*/

// Definition for a Node.
class Node {
 public:
  int val;
  vector<Node *> children;

  Node() {}

  Node(int _val) {
    val = _val;
  }

  Node(int _val, vector<Node *> _children) {
    val = _val;
    children = _children;
  }
};


class Solution {
 public:
  int maxDepth(Node *root) {
    if (root == nullptr) {
      return 0;
    }
    int depth = 0;
    for (int i = 0; i < root->children.size(); i++) {
      depth = max(depth, maxDepth(root->children(i)));
    }
    return depth + 1;
  }
};

class Solution {
 public:
  int maxDepth(Node *root) {
    if (root == nullptr) {
      return 0;
    }
    queue<Node *> qu;
    qu.push(root);
    int ans = 0;
    while (!qu.empty()) {
      int size = qu.size();
      while (size > 0) {
        Node *node = qu.front();
        qu.pop();
        vector<Node *> children = node->children;
        for (auto child : children) {
          qu.push(child);
        }
        size--;
      }
      ans++;
    }
    return ans;
  }
};

int main() {
  int n = 101;
  vector<int> num = {1, 2, 3, 4, 5};
  Solution app;
  vector<string> ans = app.maxDepth(num);
  cout << ans.size() << endl;
  return 0;
}