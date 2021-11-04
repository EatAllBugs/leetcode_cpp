#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
using namespace std;
/*
给你一个整数 n ，请你生成并返回所有由 n 个节点组成且节点值
从 1 到 n 互不相同的不同 二叉搜索树 。可以按 任意顺序 返回答案。
*/

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  vector<TreeNode *> generateTrees(int n) {
    if (n) {
      return generateTree(1, n);
    } else {
      return vector<TreeNode *> {};
    }
  }
  vector<TreeNode *> generateTree(int left, int right) {
    vector<TreeNode *> ans;
    if (left > right) {
      ans.push_back(nullptr);
      return ans;
    }
    for (int i = left; i <= right; i++) {
      vector<TreeNode *> left_tree = generateTree(left, i);
      vector<TreeNode *> right_tree = generateTree(i + 1, right);
      for (auto &left_node : left_tree) {
        for (auto &right_node : right_tree) {
          TreeNode *t = new TreeNode(i);
          t->left = left_node;
          t->right = right_node;
          ans.push_back(t);
        }
      }
    }
    return ans;
  }
};

int main() {
  return 0;
}