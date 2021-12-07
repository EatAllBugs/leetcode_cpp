/*
 * @lc app=leetcode.cn id=563 lang=cpp
 *
 * [563] 二叉树的坡度
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
  int res = 0;
  int findTilt(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    sum(root);
    return res;
  }
  int sum(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    int sum_left = sum(root->left);
    int sum_right = sum(root->right);
    res += fabs(sum_left - sum_right);
    return root->val + sum_left + sum_right;
  }
};
// @lc code=end

