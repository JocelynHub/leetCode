/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 * 去构成图，然后看最短路径
 */

// @lc code=start
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <set>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        map<string,vector<string>> graph;
        constructGraph(beginWord,wordList,graph);
        return BFSGraph(beginWord,endWord,graph);
    }
    //判断是否相连
    bool connect(const string &word1,const string &word2){
        int cnt = 0;
        for (int i = 0; i < word1.size(); i++)
        {
            if(word1[i] != word2[i]){
                cnt++;
            }
        }
        return cnt == 1;
    }
    //去构建图
    void constructGraph(string &beginWord,vector<string> wordList,map<string,vector<string>> &graph){
        wordList.push_back(beginWord);

        for (int i = 0; i < wordList.size(); i++)
        {
            graph[wordList[i]] = vector<string>();
        }
        

        for (int i = 0; i < wordList.size(); i++)
        {
            for (int j = i + 1; j < wordList.size(); j++)
            {
                if(connect(wordList[i],wordList[j])){
                    graph[wordList[i]].push_back(wordList[j]);
                    graph[wordList[j]].push_back(wordList[i]);
                }
            }    
        }
        
    }
    
    //去宽度搜索这个图
    int BFSGraph(string &beginWord,string &endWord,map<string,vector<string>> &graph){
        queue<pair<string,int>>Q;
        set<string>visit;

        Q.push(make_pair(beginWord,1));
        visit.insert(beginWord);
        while(!Q.empty()){
            string node = Q.front().first;
            int step = Q.front().second;
            Q.pop();
            if(node == endWord)
                return step;
            const vector<string> neighbors = graph[node];
            for (int i = 0; i < neighbors.size(); i++)
            {
                if(visit.find(neighbors[i]) == visit.end()){
                    Q.push(make_pair(neighbors[i],step + 1));
                    visit.insert(neighbors[i]);
                }
            }
        }
        return 0;
    }
};
// @lc code=end

