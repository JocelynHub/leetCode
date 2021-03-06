/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int begin = 0;
        int end = nums.size() - 1;
        int index = -1;
        while(index == -1)//等于-1 表示还没有找到
        {
            int mid = (begin + end) / 2;
            if(target == nums[mid])
                index = mid;
            if(target < nums[mid])
            {
                if(mid == 0 || target > nums[mid - 1])
                    index = mid;
                end = mid - 1;
            }
            if(target > nums[mid])
            {
                if(mid == nums.size() -1 || target < nums[mid + 1])
                    index = mid + 1;//注意这里的临界值
                begin  = mid + 1;
            }
        }
        return index;
    }
};
// @lc code=end

