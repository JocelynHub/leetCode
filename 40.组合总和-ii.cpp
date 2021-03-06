/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 * 剪枝思想 一旦已经超出target 直接return
 */

// @lc code=start
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> item;
        set<vector<int>> res_set;

        sort(candidates.begin(),candidates.end());//这个也很关键
        int sum = 0;
        generate(0,candidates,target,sum,item,result,res_set);
        return result;
    }
private:
    void generate(int i,vector<int> &candidates,int target,int &sum,vector<int> &item,vector<vector<int>> &result,set<vector<int>> &res_set)
    {
        if(i >= candidates.size() || sum > target)
            return;
        sum += candidates[i];
        item.push_back(candidates[i]);

        if(target == sum && res_set.find(item) == res_set.end())
        {
            result.push_back(item);
            res_set.insert(item);
        }
        generate(i + 1,candidates,target,sum,item,result,res_set);
        sum -= candidates[i];
        item.pop_back();
        generate(i + 1,candidates,target,sum,item,result,res_set);
    }
};
// @lc code=end

