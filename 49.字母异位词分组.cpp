/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 * 思想1：
 * 将每个单词排序，排序后的作为key值，如果key值一样，放到同一个哈希表链中
 * 思路2：
 * 以26个字母表为一个模板，给各个字符串打分，分值一样挂在同一个哈希表链中
 */

// @lc code=start
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace  std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> anagram;
        vector<vector<string>>result;
        for (int i = 0;i < strs.size();i++)
        {
            string temp = strs[i];
            std::sort(temp.begin(),temp.end());

            if(anagram.find(temp) == anagram.end()){
                vector<string> item;
                item.push_back(strs[i]);
                anagram[temp] = item;
            }
            else{
                anagram[temp].push_back(strs[i]);
            }
        }
        map<string,vector<string>> ::iterator it;
        for (it = anagram.begin(); it != anagram.end();it++)
        {
            result.push_back((*it).second);
        }
        return result;
    }
};
// @lc code=end

