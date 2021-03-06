/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 * 因为题目描述的是 当前元素的值表示 最远 可跳跃，表示是可以选择不进行 最远步数的跳跃的，也是这一点 去考虑 贪心算法 
 * 每一步要走最远 可能在最后时刻 有富余 可以选择不走最大步数
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int>  toMaxIndex;//表示每个位置 可以跳至最远需要的步数 错误 这个表述 应该对应的是 num[i] 而不是 i + num[i]
                               //表示每个位置 可以跳至最远的下标
        for (int i = 0; i < nums.size(); i++)
        {
            toMaxIndex.push_back(i + nums[i]);
        }//每个位置 有自己对应的跳的最远的index

        int jumpToIndex = 0;//初始化 第0个元素开始跳跃
        int currToMaxIndex = toMaxIndex[0];//第0个元素 最远可以跳的下标

        while(jumpToIndex < toMaxIndex.size() && jumpToIndex <= currToMaxIndex)
        {
            //在最大步数范围内 并且 不超出最远

            //如果跳至的当前步骤的下标对应的跳至最远下标值 超出了当前的最大值 更新
            if(currToMaxIndex < toMaxIndex[jumpToIndex])
            {
                currToMaxIndex = toMaxIndex[jumpToIndex];
            }
            jumpToIndex++;
        }

        if(jumpToIndex == toMaxIndex.size())//== 是因为 while中已经限制了 最远
            return true;
        return false;
        
    }
};
// @lc code=end

