/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
 * 层次遍历二叉树 每一层的 最后一个节点
 * 怎样记录 每个节点在第几层呢
 * 将节点和层数 绑定为pair 压入队列时，将节点与层数同事压入队列，并记录每一层中出现的最后一个节点 因为是层次遍历 所以 这个右侧值在不断更新就可以了
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>views;
        queue<pair<TreeNode*,int>> Q;
        if(root)
            Q.push(make_pair(root,0));
        while(!Q.empty())
        {
            TreeNode *node = Q.front().first;
            int depth = Q.front().second;

            Q.pop();
            if(views.size() == depth)//说明这一次没有放过东西
                views.push_back(node->val);
            else
            {
                views[depth] = node->val;
            }

            if(node->left)//按照宽度遍历的想法
                Q.push(make_pair(node->left,depth + 1));
            if(node->right)
                Q.push(make_pair(node->right,depth + 1));
            
        }
        return views;

    }
};
// @lc code=end

