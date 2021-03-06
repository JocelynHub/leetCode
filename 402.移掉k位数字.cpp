/*
 * @lc app=leetcode.cn id=402 lang=cpp
 *
 * [402] 移掉K位数字
 * 通过举例：从高位到地位 比较去掉哪一位，剩下的字符串可以是最小的数字
 * 通过比较 当前位 和 下一位 如果 当前位 小于 下一位 就保留 当前位， 如果当前位 大于 下一位，就删除当前位，因为 会 为当前位 寻找合适的继承人 
 * 使用 “栈”的思想 来操作，为了遍历方便 可以使用vector
 */

// @lc code=start
#include <vector>
#include <string>
using namespace  std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<int> S;
        string result = "";

        for (int i = 0; i < num.length(); i++)
        {
            int number = num[i] - '0';
            while(!S.empty() && k > 0 && S.back() > number)//不空 有的删 比当前的栈顶元素大
            {
                S.pop_back();
                k--;
            }
            if(number != 0 || S.size() != 0)//这个是针对数字0的考虑，只要栈中的首位不是0 就可以放到栈中
            {
                S.push_back(number);
            }
        }

        while(S.size() != 0 && k > 0 )//如果栈不为空，且还需要删，就从栈顶删除
        {
            S.pop_back();
            k--;
        }
            
        for (int i = 0; i < S.size(); i++)
        {
            result.append(1,S[i] + '0');
        }
        if(result == "")//针对例三的考虑
            result = "0";
        return result;
        
    }
};
// @lc code=end

