/*
 * @lc app=leetcode.cn id=473 lang=cpp
 *
 * [473] 火柴拼正方形
 * 优化1.n个火柴杆的总和对4取余需要为0，否则返回假
 * 优化2.火柴杆按照从大到小的顺序排序，先尝试大的减少回溯的可能性
 * 优化3.每次放置时，每条边上不可放置超过总和1/4长度的火柴杆
 */

// @lc code=start
// #include <vector>
// #include <algorithm>
// using namespace std;
// class Solution {
// public:
//     bool makesquare(vector<int>& nums) {
//         if(nums.size() < 4){
//             return false;
//         }
//         int sum = 0;
//         for (int i = 0; i < nums.size(); i++)
//         {
//             sum += nums[i];
//         }
//         if(sum % 4)
//             return false;
//         sort(nums.rbegin(),nums.rend());
//         int bucket[4] = {0};
//         return generate(0,nums,sum / 4, bucket);
//     }
//     bool generate(int i,vector<int> &sticks,int target,int bucket[]){
//         if(i >= sticks.size()){//这个说明试光了所有的火柴
//             return bucket[0] == target && bucket[1] == target
//             && bucket[2] == target && bucket[3] == target;
//         }
//         //尝试着将i这个火柴放到这4个桶中
//         for (int j = 0; j < 4; j++)
//         {
//             if(bucket[j] + sticks[i] > target){
//                 continue;
//             }
//             bucket[j] += sticks[i];
//             if(generate(i + 1,sticks,target,bucket)){
//                 return true;
//             }
//             bucket[j] -= sticks[i];
//         }
//         return false;
//     }
// };

//思路二 使用位运算的方法
//知道所有杆，知道所有杆的总和，可以知道构成正方形需要的每个边的长度
//每个长度相当于画了个范围，找出满足这个范围的子集ok_subset
//在ok_subset中，两两求交，如果没有交集 说明没有使用同一个火柴，将这种两两集合求并，构成ok_half集合
//在ok_half中再去两两求交，如果没有交集 说明使用的不是同一个子集
//
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool makesquare(vector<int>& nums) {
        if(nums.size() < 4){
            return false;
        }
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        if(sum % 4){
            return false;
        } 

        int target = sum / 4;
        vector<int> ok_subset;
        vector<int> ok_half;

        int all = 1 << nums.size();//这里其实是构成了2^7个选择，在这个范围内，这个火柴要不要，是0 还是 1
        for (int i = 0; i < all; i++)
        {
            int sum = 0;
            for (int j = 0; j < nums.size(); j++)
            {
                if(i & (1 << j))//代表着这个i子集内，如果第j个火柴有用到，其实nums个火柴已经排好顺序，就看i子集对应的位置上有没有第j个火柴
                    sum += nums[j];
            }
            if(sum == target){
                ok_subset.push_back(i);//这里不是push_back(sum)
            }
        }
        for (int i = 0; i < ok_subset.size(); i++)
        {
            for (int j = i + 1; j < ok_subset.size(); j++)
            {
                if((ok_subset[i] & ok_subset[j]) == 0){
                    ok_half.push_back(ok_subset[i] | ok_subset[j]);
                }
            }
        }
        for (int i = 0; i < ok_half.size(); i++)
        {
            for (int j = i + 1; j < ok_half.size(); j++)
            {
                if((ok_half[i] & ok_half[j]) == 0){
                    return true;
                }
            }
            
        }
        return false;
    }

};
// @lc code=end

