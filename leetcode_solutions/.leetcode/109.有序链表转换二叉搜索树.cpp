/*
 * @lc app=leetcode.cn id=109 lang=cpp
 *
 * [109] 有序链表转换二叉搜索树
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
  TreeNode *sortedListToBST(ListNode *head) {
    if (head == nullptr) {
      return nullptr;
    } else if (head->next == nullptr) {
      return new TreeNode(head->val);
    }
    ListNode* pre = head;
    ListNode* p = pre->next;
    ListNode* q = p->next;
    //找到链表的中点p
    while (q != nullptr && q->next != nullptr) {
      pre = pre->next;
      p = pre->next;
      q = q->next->next;
    }
    //将中点左边的链表分开
    pre->next = nullptr;
    TreeNode* root = new TreeNode(p->val);
    root->left = sortedListToBST(head);
    root->right = sortedListToBST(p->next);
    return root;
  }
};
// @lc code=end

