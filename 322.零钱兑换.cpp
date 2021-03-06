/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        vector<int> dp;
        for (int i = 0; i <= amount; i++)//<= amount
        {
            dp.push_back(-1);
        }
        dp[0] = 0;//这一句不能少
        for (int i = 1; i <= amount; i++)//<= amount 这个也很关键
        {
            for (int j = 0; j < coins.size(); j++)
            {
                if(i - coins[j] >= 0 && dp[i - coins[j]] != -1 ){//i == 2 不足以使用金币5，金币5委屈
                    if(dp[i] == -1 || dp[i] > dp[i - coins[j]] +  1)
                        dp[i] = dp[i - coins[j]] + 1;
                }
            }
            
        }
        return dp[amount];
    }
};
// @lc code=end

