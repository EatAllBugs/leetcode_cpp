#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
#include<numeric>
#include<unordered_set>
#include<map>
using namespace std;
/*
给你一个整数 columnNumber ，返回它在 Excel 表中相对应的列名称。

例如：
A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28
*/
class Solution {
 public:
  string convertToTitle(int columnNumber) {
    string ans;
    while (columnNumber > 0) {
      --columnNumber;
      int mod = columnNumber % 26;
      char c = mod + 'A';
      ans += c;
      columnNumber = columnNumber / 26;
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
  int titleToNumber(string columnTitle) {
    reverse(columnTitle.begin(), columnTitle.end());
    int ans = 0;
    for (int i = 0; i < columnTitle.size(); i++) {
      ans += (columnTitle[i] + 1 - 'A') * pow(26, i);
    }
    return ans;
  }
  bool containsDuplicate(vector<int> &nums) {
    map<int, int> bp;
    for (auto &n : nums) {
      bp[n]++;
      if (bp[n] > 1) {
        return true;
      }
    }
    return false;
  }
  /*
  给定一个整数数组和一个整数 k，判断数组中是否存在两个不同的索引 i 和 j，
  使得 nums [i] = nums [j]，并且 i 和 j 的差的 绝对值 至多为 k。

  示例 1:
  输入: nums = [1,2,3,1], k = 3
  输出: true

  示例 2:
  输入: nums = [1,0,1,1], k = 1
  输出: true

  示例 3:
  输入: nums = [1,2,3,1,2,3], k = 2
  输出: false
  */
  bool containsNearbyDuplicate(vector<int> &nums, int k) {
    unoerdered_map<int, int> bp;
    for (int i = 0; i < nums.size(); i++) {
      if (bp.find(nums[i]) != bp.end() && (i - bp.find(nums[i])->second) <= k) {
        return true;
      }
      bp[nums[i]] = i;
    }
    return false;
  }
  /*
  给你一个整数 n，请你判断该整数是否是 2 的幂次方。如果是，返回 true ；否则，返回 false 。

  如果存在一个整数 x 使得 n == 2** x ，则认为 n 是 2 的幂次方。

  */
  bool isPowerOfTwo(int n) {
    if (n == 1) {
      return true;
    }
    if (n % 2 == 1 || n == 0) {
      return false;
    }
    if (n < 0) {
      n = abs(n);
    }
    while (n > 0) {
      n = n / 2;
      if (n % 2 == 1 && n != 1) {
        return false;
      }
    }
    return true;
  }
  /*
  给你一个整数 n ，请你判断 n 是否为 丑数 。如果是，返回 true ；否则，返回 false 。
  丑数 就是只包含质因数 2、3 和/或 5 的正整数。
  */

  bool isUgly(int n) {
    if (n <= 0) {
      return false;
    }
    int tmp = n;
    while (n > 0) {
      if (n % 2 == 0) {
        n /= 2;
      }
      if (n % 3 == 0) {
        n /= 3;
      }
      if (n % 5 == 0) {
        n /= 5;
      }
      if (n % 2 != 0 && n % 3 != 0 && n % 5 != 0 && n != 1) {
        return false;
      }
      if (n == 1) {
        break;
      }
    }
    return true;
  }
  /*
  给定一个包含 [0, n] 中 n 个数的数组 nums ，找出 [0, n] 这个范围内没有出现在数组中的那个数。

  示例 1：
  输入：nums = [3,0,1]
  输出：2
  解释：n = 3，因为有 3 个数字，所以所有的数字都在范围 [0,3] 内。
  2 是丢失的数字，因为它没有出现在 nums 中。
  */
  int missingNumber(vector<int> &nums) {
    int miss = nums.size();
    for (int i = 0; i < nums.size(); i++) {
      miss ^= i ^ nums[i];
    }
    return miss;
  }
  /*
  283. 移动零
  给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
  示例:
  输入: [0,1,0,3,12]
  输出: [1,3,12,0,0]
  说明:
  必须在原数组上操作，不能拷贝额外的数组。
  尽量减少操作次数。
  */
  void moveZeroes(vector<int> &nums) {
      int slow = 0;
      for(int i = 0; i < nums.size(); i++){
          if(nums[i] != 0){
              nums[slow++] = nums[i];
          }
      }
      for(int i = slow; i < nums.size(); i++){
          nums[i] = 0;
      }
  }
};

int main() {
  int g = 28;
  string s = "FXSHRXW";
  Solution app;
  int ans = app.titleToNumber(s);
  cout << ans << endl;
  return 0;
}