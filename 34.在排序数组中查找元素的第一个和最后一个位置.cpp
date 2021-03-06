/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int >res;
        res.push_back(left_found(nums,target));
        res.push_back(right_found(nums,target));
        return res;
    }
    int left_found(vector<int> &nums,int target)
    {
        int begin = 0;
        int end = nums.size() - 1;
        while(begin <= end)
        {
            int mid = (begin + end) / 2;
            if(target == nums[mid])
            {
                if(mid == 0 || nums[mid - 1] < target)
                    return mid;
                end = mid - 1;
            }
            else if(target < nums[mid])
                end = mid -1;
            else if(target > nums[mid])
                begin = mid + 1;
        }
        return -1;
    }
    int right_found(vector<int>&nums,int target)
    {
        int begin = 0;
        int end = nums.size() - 1;
        while(begin <= end)
        {
            int mid = (begin + end) / 2;
            if(target == nums[mid])
            {
                if(mid == nums.size() - 1 || nums[mid + 1] > target)
                {
                    return mid;
                }
                begin  = mid + 1;
            }
            else if(target < nums[mid])
                end = mid -1;
            else if(target > nums[mid])
                begin = mid + 1;
        }
        return -1;
    }
};
// @lc code=end

