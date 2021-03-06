/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 * 要求时间复杂度为常数级O(1)
 * 结论：
 * 1.一个变量min无法完成纪录栈中所有状态下的最小值
 * 2.栈的每个状态，都需要一个变量纪录最小值
 * 3.用另一个栈，存储每一步状态的最小值
 */

// @lc code=start
#include <stack>
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        _data.push(x);
        if(_min.empty())
            _min.push(x);
        else{
            if(x>_min.top()){
                x = _min.top();
            }
            _min.push(x);
        }
    }
    
    void pop() {
        _data.pop();
        _min.pop();

    }
    
    int top() {
        return _data.top();
    }
    
    int getMin() {
        return _min.top();
    }
    private:
    std::stack<int> _data;
    std::stack<int> _min;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

