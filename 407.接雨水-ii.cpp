/*
 * @lc app=leetcode.cn id=407 lang=cpp
 *
 * [407] 接雨水 II
 * 思路：
 * 想象为从外向内漫水
 * 搜索队列使用 优先级队列（堆）
 * 越低矮的点 优先级越高（最小堆）
 * 需要使用二维数组对进入 队列的点进行标记，之后搜索到该点后，不再push到队列中
 * 只要优先级队列不空，即可取出优先级队列的队头元素进行搜索，按照上下左右四个方向进行拓展，拓展过程中忽略超出边界和已经进入队列的点
 * 
 */

// @lc code=start
#include <vector>
#include <queue>
using namespace std;
struct Qitem{
    int x;
    int y;
    int h;
    Qitem(int _x,int _y,int _h){
        x = _x;
        y = _y;
        h = _h;
    }
};
struct cmp{
    bool operator()(const Qitem &a, const Qitem &b){
        return a.h > b.h;
    }
};
class Solution {
public:

    int trapRainWater(vector<vector<int>>& heightMap) {
        priority_queue<Qitem,vector<Qitem>,cmp> Q;
        //先将边界的元素放进去
        if(heightMap.size() < 3 || heightMap[0].size() < 3){
            return 0;
        }
        int row = heightMap.size();
        int column = heightMap[0].size();
        vector<vector<int>> mark;
        //初始化用来标记的数组
        for (int i = 0; i < row; i++)
        {
            mark.push_back(vector<int>());
            for (int j = 0; j < column; j++)
            {
                mark[i].push_back(0);
            }
        }
        for (int i = 0; i < row; i++)
        {
            Q.push(Qitem(i,0,heightMap[i][0]));
            mark[i][0] = 1;
            Q.push(Qitem(i,column - 1,heightMap[i][column - 1]));
            mark[i][column - 1] = 1;
        }

        for (int i = 1; i < column - 1; i++)
        {
            Q.push(Qitem(0,i,heightMap[0][i]));
            mark[0][i] = 1;
            Q.push(Qitem(row - 1,i,heightMap[row - 1][i]));
            mark[row - 1][i] = 1;
        }
        
        static const int dx[] = {-1,1,0,0};
        static const int dy[] = {0,0,-1,1};
        int result = 0;
        while(!Q.empty()){
            int x = Q.top().x;
            int y = Q.top().y;
            int h = Q.top().h;
            Q.pop();
            //拓展4个方向
            for (int i = 0; i < 4; i++)
            {
                int newx = x + dx[i];
                int newy = y + dy[i];

                if(newx < 0 || newx >= row
                 || newy < 0 || newy >= column || mark[newx][newy])
                 {
                    continue;
                 }
                 if(h > heightMap[newx][newy]){
                    result += h - heightMap[newx][newy];
                    heightMap[newx][newy] = h;
                 }
                 Q.push(Qitem(newx,newy,heightMap[newx][newy]));
                 mark[newx][newy] = 1;
            }
            
        }
        return result;
        
    }
};
// @lc code=end

