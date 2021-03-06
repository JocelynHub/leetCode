/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 * 要先放药片，在倒过来的时候 药片才在最上方
 * push的操作O(N)
 */

// @lc code=start
#include <queue>
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        std::queue<int> temp_queue;
        temp_queue.push(x);
        while(!_data.empty())
        {
            temp_queue.push(_data.front());
            _data.pop();//这两句需要同步
        }
        while(!temp_queue.empty())
        {
            _data.push(temp_queue.front());
            temp_queue.pop();//这两句也需要同步
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int x = _data.front();
        _data.pop();
        return x;
    }
    
    /** Get the top element. */
    int top() {
        return _data.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return _data.empty();
    }
    private:
    std::queue<int> _data;//栈中存储元素的顺序
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

