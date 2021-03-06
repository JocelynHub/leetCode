/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<vector<int>> mark;
        vector<string> location;
        for (int i = 0; i < n; i++)
        {
            mark.push_back(vector<int>());
            for (int j = 0; j < n; j++)
            {
                mark[i].push_back(0);
            }
            location.push_back("");
            location[i].append(n,'.');
        }
        generate(0,n,location,result,mark);
        return result;
        
    }

    void generate(int k,int n,vector<string> &location,vector<vector<string>> &result,vector<vector<int>>&mark)
    {
        if(k == n)//k表示正在尝试的第K行 location 表示 当前行的结果
        {
            result.push_back(location);
            return;
        }
        for (int i = 0; i < n; i++)//按顺序 尝试0到n-1 列
        {
            if(mark[k][i] == 0)
            {
                vector<vector<int>> tempMark = mark;
                location[k][i] = 'Q';
                put_down_the_queen(k,i,mark);
                generate(k + 1,n,location,result,mark);
                //回溯
                mark = tempMark;
                location[k][i] = '.';
            }
        } 
    }
    void put_down_the_queen(int x,int y,vector<vector<int>> &mark)
    {
        static int dx[] = {-1,1,0,0,-1,-1,1,1};
        static int dy[] = {0,0,-1,1,-1,1,-1,1};
        //8个方向，每个方向延伸 n-1
        mark[x][y] = 1;
        for (int i = 0; i < 8; i++)
        {
            for (int j = 1; j < mark.size(); j++)
            {
                int newX = x + j*dx[i];
                int newY = y + j*dy[i];
                if(newX >= 0 && newX < mark.size() && newY >= 0 && newY < mark.size())
                {
                    mark[newX][newY] = 1;
                }
            } 
        }
    }
};
// @lc code=end

