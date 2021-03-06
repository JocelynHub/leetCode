/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 * 最大堆 堆顶 是最大值 左 右分支也是最大堆
 * 最小堆 堆顶 是最小值 左 右分支也是最小堆
 * std::priority_queue<int> big_heap;//默认构造是 最大堆
 * std::priority_queue<int,std::vector<int>,std::greater<int>> small_heap;//最小堆的构造方法
 * std::priority_queue<int,std::vector<int>,std::less<int>> big_heap2;//最大堆的构造方法
 * 思想：维护一个K个大小的最小堆，堆顶是最小的，堆顶就是想要的元素
 * N*log(k),数组长度是N
 */
  
// @lc code=start
#include <queue>
#include <vector>
class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        std::priority_queue<int,std::vector<int>,std::greater<int>> Q;
        for (int i = 0; i < nums.size(); i++)
        {
            if(Q.size()< k)
            {
                Q.push(nums[i]);
            }
            else
            {
                if(Q.top() < nums[i])
                {
                    Q.pop();
                    Q.push(nums[i]);
                }    

            }
            
        }
        return Q.top();
        
    }
};
// @lc code=end

