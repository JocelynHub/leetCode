/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 * 对于某个气球 至少用一只弓箭射穿
 * 需要一只弓箭 尽可能多的射穿气球
 * 射击区间 可以伸缩 气球区间是固定的
 * 去遍历气球的区间 修改  设计区间  如果不行了 就加一箭
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    static bool cmp(const vector<int> &a, const vector<int>&b)
    {
        return a[0] < b[0];//升序 只比较左端点
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size() == 0)
            return 0;
        
        sort(points.begin(),points.end(),cmp);//对气球的左端点进行排序
        int shootNum = 1;//初始化为1 而不是0
        int shootBegin = points[0][0];//射击左端点 在最左侧 会根据情况更新
        int shootEnd = points[0][1];

        for (int i = 0; i < points.size(); i++)
        {
            if(shootEnd >= points[i][0])//射击右端点不断拉长的过程
            {
                shootBegin = points[i][0];
                if(shootEnd > points[i][1])//射击右端点不断拉长的过程
                    shootEnd = points[i][1];//会影响下一个 判断区间
            }
            else
            {
                shootNum++;
                shootBegin = points[i][0];
                shootEnd = points[i][1];
            }
            
        }
        return shootNum;
        
    }
};
// @lc code=end

