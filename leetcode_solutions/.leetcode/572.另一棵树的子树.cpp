/*
 * @lc app=leetcode.cn id=572 lang=cpp
 *
 * [572] 另一棵树的子树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
 public:
  bool isSubtree(TreeNode *root, TreeNode *subRoot) {
    if (root == nullptr && subRoot == nullptr) {
      return true;
    }
    if (root == nullptr && subRoot != nullptr) {
      return false;
    }
    if (isSameTree(root, subRoot) || isSubtree(root->left, subRoot) ||
      isSubtree(root->right, subRoot)) {
      return true;
    }
    return false;
  }
  bool isSameTree(TreeNode *root, TreeNode *subRoot) {
    if (root == nullptr && subRoot == nullptr) {
      return true;
    }
    if (root == nullptr && subRoot != nullptr || root != nullptr && subRoot == nullptr) {
      return false;
    }
    if (root && subRoot && root->val == subRoot->val && isSameTree(root->left, subRoot->left) &&
      isSameTree(root->right, subRoot->right)) {
      return true;
    }
    return false;
  }
};
// @lc code=end

