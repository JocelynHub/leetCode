/*
 * @lc app=leetcode.cn id=174 lang=cpp
 *
 * [174] 地下城游戏
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if(dungeon.size() == 0)
            return 0;
        int row = dungeon.size();
        int column = dungeon[0].size();

        vector<vector<int>> dp(row,vector<int>(column,0));
        //dp[row - 1][column - 1] = max(1, dungeon[row - 1][column - 1]);
        dp[row - 1][column - 1] = max(1, 1 - dungeon[row - 1][column - 1]);//这里有个1-
        for (int i = row - 2; i >= 0; i--)
        {
            //dp[i][0] = max(1,dp[i + 1][0] - dungeon[i][0]);
            dp[i][column - 1] = max(1,dp[i + 1][column - 1] - dungeon[i][column - 1]);
        }
        for (int i = column - 2; i >= 0; i--)
        {
            //dp[0][i] = max(1,dp[0][i + 1] - dungeon[0][i]);
            dp[row - 1][i] = max(1,dp[row - 1][i + 1] - dungeon[row - 1][i]);
        }
        for (int i = row - 2; i >= 0; i--)
        {
            for (int j = column - 2; j >= 0; j--)
            {
                int dp_min = min(dp[i + 1][j],dp[i][j + 1]);
                dp[i][j] = max(1,dp_min - dungeon[i][j]);
            }
        }
        return dp[0][0];
    }
};
// @lc code=end

