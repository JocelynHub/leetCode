/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 * 公共祖先肯定在 从根节点 到两个子孙的路径上，所以讲两个路径捋直了，寻找两个路径中距离根节点最远的点，两个路径上最后一个相同的节点
 * 标志位 如果已经找到了该节点 递归可以停止
 * 同样用栈来存储 路径信息
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
using namespace std;
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> node_p_path;
        vector<TreeNode*> node_q_path;
        vector<TreeNode*> path;
        int finish = 0;
        preOrder(root,p,node_p_path,path,finish);
        path.clear();
        finish = 0;
        preOrder(root,q,node_q_path,path,finish);

        int len = 0;
        if(node_p_path.size() < node_q_path.size())
            len = node_p_path.size();
        else
            len = node_q_path.size();

        TreeNode *result = nullptr;
        for (int i = 0; i < len; i++)
        {
            if(node_p_path[i] == node_q_path[i])
                result = node_p_path[i];
        }
        return result;
        
    }
    void preOrder(TreeNode *node,TreeNode* target,vector<TreeNode*> &result,vector<TreeNode*> &path,int &finish)
    {
        if(!node || finish)
            return;
        path.push_back(node);
        if(target == node)
        {
            result = path;
            finish = 1;
        }
            
        preOrder(node->left,target,result,path,finish);
        preOrder(node->right,target,result,path,finish);
        path.pop_back();
    }
};
// @lc code=end

