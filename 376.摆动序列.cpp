/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 * 状态机转换 简单些
 * 在up峰值 和 down谷底 容易形成摇摆序列
 */

// @lc code=start
#include <vector>
class Solution {
public:
    int wiggleMaxLength(std::vector<int>& nums) {
        if(nums.size() < 2)
            return nums.size();//当序列元素个数小于2时，直接是摇摆序列
        static const int BEGIN = 0;
        static const int UP = 1;
        static const int DOWN = 2;

        int STATE = BEGIN;
        int maxLen = 1;
        for (int i = 1; i < nums.size(); i++)//注意开始的位置
        {
            switch (STATE)
            {
            case BEGIN:
                if(nums[i-1] < nums[i])
                {
                    STATE = UP;
                    maxLen ++;//后面不会再有 进入BEGIN的状态了，所以如果只有两个元素还是要++ 的
                }
                else if(nums[i-1] > nums[i])//是不包括等于的，等于不发生状态转换
                {
                    STATE = DOWN;
                    maxLen++;//后面不会再有 进入BEGIN的状态了，所以如果只有两个元素还是要++ 的
                }
                break;
            case UP:
                if(nums[i-1]>nums[i])
                {
                    STATE = DOWN;
                    maxLen++;
                }
                break;
            case DOWN:
                if(nums[i-1] < nums[i])
                {
                    STATE = UP;
                    maxLen++;
                }
                break;
            default:
                break;
            }
        }
        return maxLen;
    }
};
// @lc code=end

