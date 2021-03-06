/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 * 需要明确什么时候跳跃最合适
 * 如果提早跳跃，可能增加跳跃次数
 * 如果在位置i之前都没有跳跃，可能无法达到最后一个位置
 * 在index i 时发现 无法跳到更远的地方了
 * 在这之前 可以跳到一个 更远的位置
 * index[i-2] 是index [0,1,2...i]中最大的 需要纪录
 * 需要对 nums中所有元素对应的可跳转最大index进行纪录
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {

        if(nums.size() < 2)//如果长度小于2  说明不用跳跃
            return 0;
        int current_Tomax_index = nums[0];//当前能跳到的最远的位置
        int pre_Tomax_index = nums[0];//之前遍历的各个位置中 可达到的最远位置 
        int jump_min = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            //i表示走到的当前位置
            if(i > current_Tomax_index)//表示到了不得不进行跳跃的时刻
            {
                jump_min++;//这里进行一次跳跃 会跳跃到 pre_max的地方
                current_Tomax_index = pre_Tomax_index;
            }
            if(pre_Tomax_index < i + nums[i])//纪录之前最大的
            {
                pre_Tomax_index = i + nums[i];
            }
        }
        return jump_min;
        

    }
};
// @lc code=end

