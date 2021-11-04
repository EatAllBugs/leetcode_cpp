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
给你二叉树的根结点 root ，请你将它展开为一个单链表：

展开后的单链表应该同样使用 TreeNode ，其中 right 子指针指向链表中下一个结点，而左子指针始终为 null 。
展开后的单链表应该与二叉树 先序遍历 顺序相同。

*/

class Solution {
 public:
  void flatten(TreeNode *root) {
    TreeNode *curr = root;
    while (curr != nullptr) {
      if (curr->left != nullptr) {
        auto next = curr->left;
        auto predecessor = next;
        while (predecessor->right != nullptr) {
          predecessor = predecessor->right;
        }
        predecessor->right = curr->right;
        curr->left = nullptr;
        curr->right = next;
      }
      curr = curr->right;
    }
  }
};

int main() {
  int n = 101;
  vector<int> num = {1, 2, 3, 4, 5};
  string s = "sascacamca";
  Solution app;
  string ans = app.(n);
  cout << ans << endl;
  return 0;
}