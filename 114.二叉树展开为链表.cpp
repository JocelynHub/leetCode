/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
 * 树的left指针为空 right指针当做next指针来用
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// //思路一 暴力解法
// #include <vector>
// using namespace std;
// class Solution {
// public:
//     void flatten(TreeNode* root) {
        
//         vector<TreeNode*> res;
//         preOrder(root,res);
//         for (int i = 1; i < res.size(); i++)
//         {
//             res[i - 1]->left = nullptr;
//             //res[i - 1]->right = res[i]->right;//
//             res[i - 1]->right = res[i];//这里注意
//         }
        
//     }
// private:
//     void preOrder(TreeNode *node,vector<TreeNode*>&vec)//注意这里的引用
//     {
//         if(!node)
//             return;
//         vec.push_back(node);
//         preOrder(node->left,vec);
//         preOrder(node->right,vec);
//     }
// };

//思路二 
//将左子树 捋直了
//将右子树 捋直了
//将左子树的last 和 右子树的头结点连接起来
//如果这个节点是 叶节点 last就是它了

//有两个需要连接的地方 node 和 left  left 和 right
#include <vector>
using namespace std;
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode *last = nullptr;
        preOrder(root,last);
    
    }
private:
    void preOrder(TreeNode *node,TreeNode* &last)//注意这里的引用 
    {
        if(!node)
            return;
        if(!node->left && !node->right)
        {
            last = node;
            return;//这里可以直接返回
        }
            

        TreeNode* leftNode = node->left;//备份左右指针,因为下面83行需要修改 85行需要使用
        TreeNode* rightNode = node->right;
        TreeNode* lastLeft = nullptr;
        TreeNode* lastRight = nullptr;
        if(leftNode)
        {
            preOrder(leftNode,lastLeft);
            //lastLeft->left = nullptr;//这里不对
            node->left = nullptr;//都是在为当前节点 服务
            //还需要将头结点连起来
            node->right = leftNode;
            last = lastLeft;
        }
        if(rightNode)
        {
            preOrder(rightNode,lastRight);
            //lastLeft->right = lastRight;//这里需要判断lastLeft是否有效
            if(lastLeft)
            {
                //lastLeft->right = lastRight;//这里有问题
                lastLeft->right = rightNode;
            }
            last = lastRight;
        }
    }
};
// @lc code=end

