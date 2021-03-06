/*
 * @lc app=leetcode.cn id=295 lang=cpp
 *
 * [295] 数据流的中位数
 * 思路：
 * 利用最大堆和最小堆，最大堆存储一半的数据，最小堆存储另外的数据
 * 维护：最大堆堆顶小于最小堆堆顶
 * 维护：两个堆之间的数目差距<=1
 * 如果是偶数个数据 两个堆元素个数相同
 * 当两个堆的数据数目不相同的情况，哪个堆多，哪个堆的堆顶就是中位数
 */

// @lc code=start
#include <queue>
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        if(big_queue.empty()){
            big_queue.push(num);
            return;
        }
        if(big_queue.size() == small_queue.size())
        {
            if(num < big_queue.top())
                big_queue.push(num);
            else
            {
                small_queue.push(num);
            }
        }
        else if(big_queue.size() > small_queue.size())
        {
            //big_queue比较多，应该放到small_queue
            //但是需要num > big_queue.top
            if(num > big_queue.top())
            {
                small_queue.push(num);
            }
            else
            {
                small_queue.push(big_queue.top());
                big_queue.pop();
                big_queue.push(num);
            }         
        }
        else if(big_queue.size() < small_queue.size())
        {
            //small_queue比较多，应该放到big_queue
            //但是需要num < small_queue.top
            if(num < small_queue.top())
                big_queue.push(num);
            else
            {
                big_queue.push(small_queue.top());
                small_queue.pop();
                small_queue.push(num);
            }
        }
    }
    
    double findMedian() {
        if(big_queue.size() == small_queue.size())
        {
            return (big_queue.top() + small_queue.top())/2.0;
        }
        else if(big_queue.size() > small_queue.size())
        {
            return big_queue.top();
        }
        else
        {
            return small_queue.top();
        }
    }
    private:
    std::priority_queue<int,std::vector<int>,std::greater<int>> small_queue;
    std::priority_queue<int,std::vector<int>,std::less<int>> big_queue;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end

