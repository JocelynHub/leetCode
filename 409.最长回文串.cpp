/*
 * @lc app=leetcode.cn id=409 lang=cpp
 *
 * [409] 最长回文串
 * 如果是每个元素的个数都是偶数个，整个字符串都可以用来构成回文
 * 但是如果有些元素只有奇数个，它们之间只能选择一个
 */

// @lc code=start
#include <string>
using namespace std;
class Solution {
public:
    int longestPalindrome(string s) {
        int char_map[128] = {0};
        int max_len = 0;
        int flag = 0;
        for (int i = 0; i < s.length(); i++)
        {
            char_map[s[i]]++;
        }
        for (int i = 0; i < 128; i++)
        {
            if(char_map[i] % 2 == 0)
            {
                max_len += char_map[i];
            }
            else
            {
                max_len += char_map[i] - 1;
                flag = 1;
            }
            
        }
        return max_len + flag;
        
        
    }
};
// @lc code=end

