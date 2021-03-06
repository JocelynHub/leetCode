/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
 * 递归 前序遍历
 * 用栈来记录 路径
 * 在左分支切换到右分支的时候，需要将左分支的点pop出来
 * 
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        vector<int>path;
        int pathRes = 0;
        preOrder(root,sum,result,path,pathRes);
        return result;
    }
private:
    void preOrder(TreeNode *node,int sum,vector<vector<int>> &result,vector<int> &path,int &pathRes)
    {
        if(!node)
            return;
        path.push_back(node->val);
        pathRes += node->val;
        if(!node->left && !node->right && sum == pathRes)
        {
            result.push_back(path);//只有当叶节点 才是个完整的路径 才会放到result中
        }
        preOrder(node->left,sum,result,path,pathRes);
        preOrder(node->right,sum,result,path,pathRes);
        pathRes -= node->val;
        path.pop_back();

    }
};
// @lc code=end

