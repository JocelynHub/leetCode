/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
// #include <vector>
// using namespace std;
// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         if(nums.size() == 0)
//             return 0;
//         vector<int> dp(nums.size(),0);
//         dp[0] = 1;//求的是长度
//         int LIS = 1;
//         for (int i = 1; i < dp.size(); i++)
//         {
//             dp[i] = 1;//首先本身长度为1
//             for (int j = 0; j < i; j++)
//             {
//                 if(nums[i] > nums[j] && dp[i] < dp[j] + 1){
//                     dp[i] = dp[j] + 1;
//                 }
//                 if(LIS < dp[i])//因为求的是 最长递增子序列
//                     LIS = dp[i];
//             }
            
//         }
//         return LIS;
        
//     }
// };

//思路2
#include <vector>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        vector<int> stack;
        stack.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++)
        {
            if(nums[i] > stack.back())
                stack.push_back(nums[i]);
            else{
                // for (int j = 0; j < stack.size(); j++)
                // {
                //     if(stack[j] >= nums[i]){//严格递增,因为这个栈中也是有顺序的，主要是在这里break出来后，后面的1就不会在替换第二个位置的2了
                //         stack[j] = nums[i];
                //         break;
                //     }
                // }

                //可以使用二分法，将结果插入到栈中
                int pos = binary_search(stack,nums[i]);
                stack[pos] = nums[i];
            }
        }
        return stack.size();
        
    }
    int binary_search(vector<int> nums,int target){
        int index = -1;
        int begin = 0;
        int end = nums.size() - 1;
        while(index == -1){
            int mid = (begin + end) / 2;
            if(target == nums[mid]){
                index = mid;
            }
            else if(target < nums[mid]){
                if(mid == 0 || target > nums[mid - 1]){
                    index = mid;
                }
                end = mid - 1;
            }
            else if(target > nums[mid]){
                if(mid == nums.size() - 1 || target < nums[mid + 1]){
                    index = mid + 1;
                }
                begin  = mid + 1;
            }
        }
        return index;
    }
};
// @lc code=end

