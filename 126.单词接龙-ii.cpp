/*
 * @lc app=leetcode.cn id=126 lang=cpp
 *
 * [126] 单词接龙 II
 * 思路构图，找路径 纪录路径 宽搜
 */

// @lc code=start
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        map<string,vector<string>>graph;
        constructGraph(beginWord,wordList,graph);
        vector<Qitem> Q;
        vector<int> endWordPos;
        BFS_Graph(beginWord,endWord,graph,Q,endWordPos);

        vector<vector<string>> result;
        for (int i = 0; i < endWordPos.size(); i++)
        {
            int pos = endWordPos[i];
            vector<string> path;
            while(pos != -1){
                path.push_back(Q[pos].node);
                pos = Q[pos].parentPos;//利用纪录的前驱节点
            }
            result.push_back(vector<string>());
            for (int j = path.size() - 1; j >= 0; j--)
            {
                result[i].push_back(path[j]);
            }
        }
        return result;
    }
    //判断是否相连
    bool connect(const string &word1, const string &word2){
        int cnt = 0;
        for (int i = 0; i < word1.size(); i++)
        {
            if(word1[i] != word2[i]){
                cnt += 1;
            }
        }
        return cnt == 1; 
    }
    //构图
    void constructGraph(string &beginWord,vector<string> &wordList,map<string,vector<string>> &graph){
        int hasBeginWord = 0;
        for (int i = 0; i < wordList.size(); i++)
        {
            if(beginWord == wordList[i]){
                hasBeginWord = 1;
            }
            graph[wordList[i]] = vector<string>();
        }

        for (int i = 0; i < wordList.size(); i++)
        {
            for(int j = i + 1;j < wordList.size();j++){
                if(connect(wordList[i],wordList[j])){
                    graph[wordList[i]].push_back(wordList[j]);
                    graph[wordList[j]].push_back(wordList[i]);
                }
            }

            if(hasBeginWord == 0 && connect(beginWord,wordList[i]))
                graph[beginWord].push_back(wordList[i]);
        }  
    }

    struct Qitem{
        string node;//搜索节点
        int parentPos;//前驱节点在队列中的位置
        int step;//到达当前节点的步数
        Qitem(string _node,int _parentPos,int _step)
            :node(_node),parentPos(_parentPos),step(_step)
        {

        }
    };

    void BFS_Graph(string &beginWord,string &endWord,map<string,vector<string>> &graph,vector<Qitem> &Q,vector<int> &endWordPos){
        //因为可能存在多条路径
        map<string,int> visit;//单词 步数
        int minStep = 0;//到达endWord的最小步数
        Q.push_back(Qitem(beginWord,-1,1));
        visit[beginWord] = 1;

        int front = 0;//队列头指针
        while(front != Q.size()){
            const string &node = Q[front].node;
            int step = Q[front].step;
            if(minStep !=0 && step > minStep){//step > minStep时，表示所有到终点的路径都搜索完成
                break;
            }
            if(node == endWord){
                minStep = step;
                endWordPos.push_back(front);
            }

            const vector<string> &neighbors = graph[node];
            for (int i = 0; i < neighbors.size(); i++)
            {
                if(visit[neighbors[i]] == step + 1 || visit.find(neighbors[i]) == visit.end()){
                    Q.push_back(Qitem(neighbors[i],front,step +1));
                    visit[neighbors[i]] = step + 1;
                }
            }
            front++;
        }
    }


};
// @lc code=end

