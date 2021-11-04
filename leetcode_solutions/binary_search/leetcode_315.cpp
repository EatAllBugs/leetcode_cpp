#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
#include<numeric>
#include<unordered_set>
using namespace std;
/*
给你一个整数数组 nums ，按要求返回一个新数组 counts 。数组 counts 有该性质：
counts[i] 的值是  nums[i] 右侧小于 nums[i] 的元素的数量。

示例 1：

输入：nums = [5,2,6,1]
输出：[2,1,1,0]
解释：
5 的右侧有 2 个更小的元素 (2 和 1)
2 的右侧仅有 1 个更小的元素 (1)
6 的右侧有 1 个更小的元素 (1)
1 的右侧有 0 个更小的元素

示例 2：

输入：nums = [-1]
输出：[0]
示例 3：

输入：nums = [-1,-1]
输出：[0,0]

*/

class Solution {
 public:
  vector<int> countSmaller(vector<int> &nums) {
    int n = nums.size();
    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++) {
      int t = 0;
      for (int j = n - 1; j > i; j--) {
        if (nums[j] < nums[i]) {
          t++;
        }
      }
      ans[i] = t;
    }
    return ans;
  }
};

int main() {
  vector<int> g {-1, -1};
  Solution app;
  vector<int> ans = app.countSmaller(g);
  string w = " hello";
  string s = "hello" + w;
  char a[3] = "ab";
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << endl;
  }
  cout << s << endl;
  cout << a[1] << endl;
  return 0;
}

/*
我们称一个数 X 为好数, 如果它的每位数字逐个地被旋转 180 度后，
我们仍可以得到一个有效的，且和 X 不同的数。要求每位数字都要被旋转。

如果一个数的每位数字被旋转以后仍然还是一个数字， 则这个数是有效的。
0, 1, 和 8 被旋转后仍然是它们自己；
2 和 5 可以互相旋转成对方（在这种情况下，它们以不同的方向旋转，换句话说，2 和 5 互为镜像）；
6 和 9 同理，除了这些以外其他的数字旋转以后都不再是有效的数字。

现在我们有一个正整数 N, 计算从 1 到 N 中有多少个数 X 是好数？

 

示例：

输入: 10
输出: 4
解释:
在[1, 10]中有四个好数： 2, 5, 6, 9。
注意 1 和 10 不是好数, 因为他们在旋转之后不变。

*/

class Solution {
 public:
  int rotatedDigits(int n) {
  }
};

class Solution {
 public:
  vector<string> summaryRanges(vector<int> &nums) {
    vector<string> ans;
    if (nums.size() == 0) {
      return ans;
    }
    int i = 0;
    while (i < nums.size()) {
      int low = i;
      i++
      while (i < nums.size() && nums[i] == nums[i - 1] + 1) {
        i++;
      }
      int high = i - 1;
      if (low < high) {
        string tmp = to_string(nums[low]) + "->" + to_string(nums[high]);
        ans.push_back(tmp);
      } else {
        ans.push_back(to_string(nums[low]));
      }
    }
    return ans;
  }
};

class Solution {
 public:
  bool isPalind(vector<int> vec) {
    int l = 0, t = vec.size() - 1;
    while (l <= r) {
      if (vec[l] != vec[r]) {
        return false;
      }
      l++;
      r--;
    }
    return true;
  }
  bool isPalindrome(ListNode *head) {
    vector<int> tmp;
    while (head) {
      tmp.push_back(head->val);
      head = head->next;
    }
    return isPalind(tmp);
  }
};

class Solution {
 public:
  bool isPowerOfThree(int n) {
    vector<int> res;
    for (int i = 1; i < INT_MAX / 3 + 1; i *= 3) {
      res.push_back(i);
    }
    res.push_back(1162261467);
    for (int i = 0; i < res.size(); i++) {
      if (n == res[i]) {
        return true;
      }
    }
    return false;
  }
};

class Solution {
 public:
  vector<int> countBits(int n) {
    vector<int> res(n + 1, 0);
    for (int i = 1; i <= n; i--) {
      res[i] = res[i & (i - 1)] + 1;
    }
    return res;
  }
};


class Solution {
 public:
  bool isPowerOfFour(int n) {
    if (n == 1) {
      return true;
    } else if (n < 4) {
      return false;
    }
    return n > 0 && 1073741824 % n == 0;
  }
};

class Solution {
 public:
  bool isvowel(char c) {
    bool low = (c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u');
    bool up = (c == 'A') || (c == 'E') || (c == 'I') || (c == 'O') || (c == 'U');
    return low || up;
  }
  string reverseVowels(string s) {
    int l = 0, r = s.size() - 1;
    while (l <= r) {
      if (isvowel(s[l]) && isvowel(s[r])) {
        char temp = s[l];
        s[l] = s[r];
        s[r] = temp;
        l++;
        r--;
      } else if (!isvowel(s[l])) {
        l++;
      } else if (!isvowel(s[r])) {
        r--;
      }
    }
    return s;
  }
};

class Solution {
 public:
  vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
    vector<int> intersect;
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int l1 = 0, l2 = 0;
    while (l1 < nums1.size() && l2 < nums2.size()) {
      if (nums1[l1] < nums2[l2]) {
        l1++;
      } else if (nums1[l1] > nums2[l2]) {
        l2++;
      } else {
        intersect.push_back(nums1[l1]);
        l1++;
        l2++;
      }
    }
    return intersect;
  }
};

class Solution {
 public:
  int firstUniqChar(string s) {
    map<char, int> bp;
    for (int i = 0; i < s.size(); i++) {
      bp[s[i]]++;
    }
    for (int i = 0; i < s.size(); i++) {
      if (bp[s[i]] == 1) {
        return i;
      }
    }
    return -1;
  }
};


class Solution {
 public:
  bool isSubsequence(string s, string t) {
    int n = s.length(), m = t.length();
    int i = 0, j = 0;
    while (i < n && j < m) {
      if (s[i] == t[j]) {
        i++;
      }
      j++;
    }
    return i == n;
  }
};

class Solution {
 public:
  string toHex(int num) {
  }
};

class Solution {
 public:
  int longestPalindrome(string s) {
    map<char, int> bp;
    for (int i = 0; i < s.size(); i++) {
      bp[s[i]]++;
    }
    int len = 0;
    for (auto a : bp) {
      len += a.second / 2;
    }
    if (len * 2 == s.size()) {
      len *= 2;
    } else {
      len = len * 2  + 1;
    }
    return len;
  }
};

class Solution {
 public:
  vector<int> findDisappearedNumbers(vector<int> nums) {
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++) {
      nums[abs(nums[i]) - 1] = -abs(nums[abs(nums[i]) - 1]);
    }
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] > 0) {
        ans.push_back(nums[i]);
      }
    }
    return ans;
  }
};

class Solution {
 public:
  int islandPerimeter(vector<vector<int> > &grid) {
    int m = grid.size();
    int n = grid[0].size();
    int ans = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 1) {
          ans += 4;
          if (i < m - 1 && grid[i + 1][j] == 1) {
            ans -= 2;
          }
          if (j  < n - 1 && grid[i][j + 1] == 1) {
            ans -= 2;
          }
        }
      }
    }
    return ans;
  }
};

class Solution {
 public:
  int findMaxConsecutiveOnes(vector<int> &nums) {
    if (nums.size() == 1) {
      return nums[0];
    }
    int res = INT_MIN;
    for (int i = 0; i < nums.size() - 1; i++) {
      if (nums[i] != 1) {
        continue;
      }
      int tmp = 1;
      while (i < nums.size() - 1 && nums[i + 1] == 1) {
        i++;
        tmp++;
      }
      res = max(res, tmp);
    }
    return res;
  }
};

class Solution {
 public:
  bool isSelfCrossing(vector<int> &distance) {
    if (distance[2] <= distance[0] && distance[3] >= distance[1]) {
      return true;
    }
    return false;
  }
};