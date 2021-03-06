/*
 * @lc app=leetcode.cn id=224 lang=cpp
 *
 * [224] 基本计算器
 * 栈来实现计算器
 * 存在数字栈 操作符栈 类似最小栈来处理
 * 状态机 概念
 * 是否进行计算的标志位
 * 处理为 long long
 */

// @lc code=start
#include <string>
#include <stack>
using namespace std;
class Solution {
public:

    int calculate(string s) {
        static const int STATE_BEGIN = 0;
        static const int NUMBER_STATE = 1;
        static const int OPERATION_STATE = 2;
        stack<long long> numberStack;
        stack<char>operationStack;

        long long number = 0;
        int state = STATE_BEGIN;
        int computeFlag = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if(' ' == s[i]){
                continue;
            }
            switch(state)
            {
                case STATE_BEGIN:
                    if(s[i]>='0' && s[i]<='9'){
                        state = NUMBER_STATE;
                    }
                    else
                    {
                        state = OPERATION_STATE;
                    }
                    i--;
                    break;
                case NUMBER_STATE:
                    if(s[i]>='0' && s[i]<='9')//将字符串转换为数字
                        number = number * 10 + s[i] - '0';
                    else//遇到了不是数字的内容，说明要先算一下，然后再退格
                    {
                        numberStack.push(number);
                        if(computeFlag == 1)//在刚刚不是数字的情况下 如果可以进行计算 计算一下
                        {
                            compute(numberStack,operationStack);
                        }
                        number=0;
                        i--;
                        state = OPERATION_STATE;
                    }
                    break;
                case OPERATION_STATE:
                    if(s[i] == '+' || s[i] == '-')
                    {
                        operationStack.push(s[i]);
                        computeFlag = 1;
                    }
                    else if(s[i] == '(')//如果遇到左括号 不能计算
                    {
                        state = NUMBER_STATE;
                        computeFlag = 0;
                    }
                    else if(s[i]>='0' && s[i]<='9')//在该状态 遇到了别的类型 就要退格 并修改当前状态
                    {
                        state = NUMBER_STATE;
                        i--;
                    }
                    else if(s[i] == ')'){//如果遇到右括号 肯定需要计算一下
                        compute(numberStack,operationStack);
                    }
                    break;
            }
        }
        if(number != 0)
        {
            numberStack.push(number);
            compute(numberStack,operationStack);
        }
        if(number ==0 && numberStack.empty())
            return 0;

        return numberStack.top();
        
    }
    //计算两个stack钟优先级的数字 并 pop 然后将结果push进去
    void compute(stack<long long> &numberStack,stack<char> &operationStack)
    {
        if(numberStack.size()<2)
            return;
        int number2 = numberStack.top();
        numberStack.pop();
        int number1 = numberStack.top();
        numberStack.pop();
        if(operationStack.top() == '+')// 左右括号没有放进来
        {
            numberStack.push(number2 + number1);
        }
        else if(operationStack.top() == '-')
            numberStack.push(number1- number2);
        operationStack.pop();
    }
};
// @lc code=end

