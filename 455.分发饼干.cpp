/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 * 两个指针，如果孩子可以被满足，两个都向后移动；如果不可以被满足 那这个糖 没用 可以被丢掉了
 */

// @lc code=start
#include <vector>
#include <algorithm>
class Solution {
public:
    int findContentChildren(std::vector<int>& g, std::vector<int>& s) {
        std::sort(g.begin(),g.end());
        std::sort(s.begin(),s.end());
        int child = 0;
        int cookie = 0;
        while(child < g.size() && cookie < s.size())
        {
            if(g[child] <= s[cookie])
            {
                child++;
            }
            cookie++;
        }
        return child;
    }
};
// @lc code=end

