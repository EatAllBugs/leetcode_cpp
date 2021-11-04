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
给你一个二叉树的根节点 root ，树中每个节点都存放有一个 0 到 9 之间的数字。
每条从根节点到叶节点的路径都代表一个数字：

例如，从根节点到叶节点的路径 1 -> 2 -> 3 表示数字 123 。
计算从根节点到叶节点生成的 所有数字之和 。

叶节点 是指没有子节点的节点。

*/

class Solution {
 public:
  int sumNumbers(TreeNode *root) {
    return dfs(root, 0);
  }
  long long dfs(TreeNode *root, long long sum) {
    if (root == nullptr) {
      return 0;
    }
    if (root->left != nullptr && root->right != nullptr) {
      return sum += root->val;
    }
    sum += root->val;
    return dfs(root->left, 10 * sum) + dfs(root->right, 10 * sum);
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

class Solution {
 public:
  int findUnsortedSubarray(vector<int> &nums) {
    if (nums.size() <= 1) {
      return 0;
    }
    int n = nums.size();
    int left = 0, right = n - 1;
    int max_num = nums[0], min_num = nums[n - 1];
    for (int i = 1; i < n; i++) {
      max_num = max(max_num, nums[i]);
      if (nums[i] < max_num) {
        left = i;
      }
      min_num = min(min_num, nums[n - i - 1]);
      if (nums[n - i - 1] > min_num) {
        right = n - i - 1;
      }
    }
    return right  > left ? right - left + 1 : 0;
  }
};