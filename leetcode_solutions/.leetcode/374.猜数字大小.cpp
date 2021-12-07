/*
 * @lc app=leetcode.cn id=374 lang=cpp
 *
 * [374] 猜数字大小
 */

// @lc code=start
/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
 public:
  int guessNumber(int n) {
      int left = 1, right = n;
      while(left < right){
          int mid = (right - left) / 2 + left;
          if(guess(mid) > 0){
              left = mid + 1;
          }else if(guess(mid) < 0){
              right = mid;
          }else{
              return mid;
          }
      }
      return left;
  }
};
// @lc code=end

