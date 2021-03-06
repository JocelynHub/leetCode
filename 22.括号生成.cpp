/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 * 总的数目会是2*n
 * 先放右括号是没有意义的 只有放了左括号 才能放右括号
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generate("",n,n,result);
        return result;
    }
private:
    void generate(string item,int leftRemain,int rightRemain,vector<string> &result)
    {
        if(leftRemain ==0 && rightRemain ==0)
        {
            result.push_back(item);//这里返回
            return;
        }
            
        
        if(leftRemain > 0)
            generate(item + "(",leftRemain-1,rightRemain,result);
        if(leftRemain < rightRemain)
            generate(item + ")",leftRemain,rightRemain - 1,result);
    }
};
// @lc code=end

