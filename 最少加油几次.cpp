#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

bool cmp(const pair<int,int> &a,const pair<int,int> &b)
{
    return a.first > b.first;//因为距离是从大到小
}
//L表示起点到终点距离 P表示起点初始油量 pair为当前加油站到终点距离，当前加油站汽油量
int get_mininum_stop(int L,int P,vector<pair<int,int>> &stops)
{
    priority_queue<int> Q;//用来存储各个站 油量的最大堆
    int result = 0;//表示中间加油的次数

    stops.push_back(make_pair(0,0));//因为没有将终点放进去
    std::sort(stops.begin(),stops.end(),cmp);

    //遍历各个加油站，查看必须进行加油的地方
    for (int i = 0; i < stops.size(); i++)
    {
        int dis = L - stops[i].first;//当前站点到终点的距离
        while(!Q.empty() && P < dis)//不得不走的时候
        {
            P += Q.top();
            Q.pop();
            result++;
        }
        if(Q.empty() && P < dis)
            return -1;
        //当前油量减去使用值
        //P -= stops[i].first; 错误
        P -= dis;//表示走过了这站

        L = stops[i].first;
        Q.push(stops[i].second);//更新L 和 最大堆
    }
    return result;
}