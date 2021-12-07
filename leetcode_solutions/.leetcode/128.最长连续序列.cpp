/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> bp;
        for(auto &x : nums){
            bp.insert(x);
        }
        int res = 0;
        for(auto x : bp){
            if(!bp.count(x - 1)){
                int y = x;
                while(bp.count(y)){
                    y++;
                }
                res = max(res, y - x);
            }
        }
        return res;
    }
};
// @lc code=end

