/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 * 仍然使用二分查找的方法，只不过 现在的搜索目标不再是单调的了，因为旋转数组的存在
 * 可以根据旋转点左右两个的大小关系，具体到在旋转数组中 在那一侧进行搜索
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int begin = 0;
        int end = nums.size() - 1;
        while(begin <= end)
        {
            int mid = (begin + end) / 2;
            if(target == nums[mid])
                return mid;
            else if(target < nums[mid])
            {
                if(nums[begin] < nums[mid])//begin-mid递增区间
                {
                    if(target >= nums[begin])
                    {
                        end = mid - 1;
                    }
                    else
                    {
                        begin  = mid + 1;
                    }
                    
                }
                else if(nums[begin] > nums[mid])//递增区间在mid后面
                {
                    end = mid - 1;
                }
                else if(nums[begin] == nums[mid])//说明目标只能在mid+1 ~ end
                {
                    begin = mid + 1;
                }
            }
            else if(target > nums[mid])
            {
                if(nums[begin] < nums[mid])//说明递增区间在begin-mid
                {
                    begin  = mid + 1;
                }
                else if(nums[begin] > nums[mid])//说明递增区间在mid后面，旋转区间在begin - mid-1
                {
                    if(target >= nums[begin])//旋转过去的 肯定比begin小
                    {
                        end = mid - 1;
                    }
                    else
                    {
                        begin = mid + 1;
                    }
                    
                }
                else if(nums[begin] == nums[mid])//说明目标只能在mid+1 - end
                {
                    begin = mid + 1;
                }
            }
        }
        return -1;
    }
};
// 1 3 4 5 6
// 3 4 5 6 1
// 4 5 6 1 3
// 5 6 1 3 4
// 6 1 3 4 5
// @lc code=end

