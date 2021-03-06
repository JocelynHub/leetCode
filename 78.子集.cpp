/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 * 递归 回溯
 */

// @lc code=start
//思路一 递归 回溯
//O(2^N) 比较暴力
//
// #include <vector>
// using namespace std;
// class Solution {
// public:
//     vector<vector<int>> subsets(vector<int>& nums) {
//         vector<vector<int>> result;
//         vector<int> item;//回溯时 产生各个子集的数组
//         result.push_back(item);
//         generate(0,nums,item,result);
//         return result;
//     }

// private:
//     void generate(int i,vector<int> &nums,vector<int> &item,
//         vector<vector<int>> &result)
//     {
//         if(i >= nums.size())
//             return;
//         item.push_back(nums[i]);
//         result.push_back(item);//将当前生成的子集添加到result中
//         generate(i + 1,nums,item,result);
//         item.pop_back();
//         generate(i+1,nums,item,result);
//     }

// };

//思路二
//位运算
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        int all_set = 1 << (nums.size());//所有子集的个数
        for (int i = 0; i < all_set; i++)
        {
            vector<int> item;
            for (int j = 0; j < nums.size(); j++)
            {
                //i 表示 当前集合所对应的整数
                //下面一步就是看当前子集 item 中包含了 nums 中的哪个元素
                if(i & (1 << j))//构造这个集合
                    item.push_back(nums[j]);
            }
            result.push_back(item);
        }
        return result;
    }
};
// @lc code=end

