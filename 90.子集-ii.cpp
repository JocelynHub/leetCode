/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 * 【1，2，1，2，2】
 * 结果【1，2，2】（0，1，3） （0，1，4）
 * 【2，1，2】
 * 两种重复
 * 所以用set去重
 */

// @lc code=start
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> item;
        set<vector<int>> res_set;
        sort(nums.begin(),nums.end());
        result.push_back(item);
        generate(0,nums,result,item,res_set);
        return result;
    }
private:
    void generate(int i,vector<int> &nums, vector<vector<int>>&result,vector<int> &item,set<vector<int>> &res_set)
    {
        if(i >= nums.size())
            return;
        item.push_back(nums[i]);//因为这个item可能会被放弃
        //if(res_set.find(nums[i]) == res_set.end())res_set中 是查看 是不是已经存在这个子序列 而不是是不是已经存在这个元素
        if(res_set.find(item) == res_set.end())
        {
            result.push_back(item);
            res_set.insert(item);
        }
        generate(i + 1,nums,result,item,res_set);
        item.pop_back();
        generate(i + 1,nums,result,item,res_set);

        
    }
};
// @lc code=end

