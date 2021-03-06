/*
 * @lc app=leetcode.cn id=315 lang=cpp
 *
 * [315] 计算右侧小于当前元素的个数
 * 归并排序 + 递归
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> count;
        vector<pair<int,int>> vec;
        for (int i = 0; i < nums.size(); i++)
        {
            vec.push_back(make_pair(nums[i],i));
            count.push_back(0);
        }
        merge_sort(vec,count);
        return count;
        
    }
private:
    void merge_sort_two_vec(vector<pair<int,int>> &subV1,vector<pair<int,int>>subV2,vector<pair<int,int>> &vec,vector<int> &count)
    {
        int i = 0;
        int j = 0;
        while(i < subV1.size() && j < subV2.size())
        {
            if(subV1[i].first <= subV2[j].first)
            {
                count[subV1[i].second] += j;//因为之前的已经加进去了
                vec.push_back(subV1[i]);
                i++;
            }
            else
            {
                vec.push_back(subV2[j]);
                j++;
            }
            
        }
        for (; i < subV1.size(); i++)
        {
            count[subV1[i].second] += j;
            vec.push_back(subV1[i]);
        }
        for (; j < subV2.size(); j++)
        {
            vec.push_back(subV2[j]);
        }
        
        
    }
    void merge_sort(vector<pair<int,int>> &vec,vector<int> &count)
    {
        if(vec.size() < 2)
            return;
        int mid = vec.size() / 2;
        vector<pair<int,int>> subV1;
        vector<pair<int,int>> subV2;
        for (int i = 0; i < mid; i++)
        {
            subV1.push_back(vec[i]);
        }
        for (int i = mid; i < vec.size(); i++)
        {
            subV2.push_back(vec[i]);
        }
        merge_sort(subV1,count);
        merge_sort(subV2,count);
        vec.clear();
        merge_sort_two_vec(subV1,subV2,vec,count);
        
    }
};
// @lc code=end

