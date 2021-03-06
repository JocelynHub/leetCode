/*
 * @lc app=leetcode.cn id=449 lang=cpp
 *
 * [449] 序列化和反序列化二叉搜索树
 * 对二叉查找树进行 前序遍历，将遍历得到的结果按顺序重新构造一个新的二叉查找树，新的二叉查找树与原二叉查找树一致
 * 只有前序可以
 * 编码时 加上#进行分隔
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

#include <string>
#include <vector>
using namespace std;
class Codec {
public:
    void change_int_to_string(int val,string &str_val)
    {
        string tmp;
        while(val)
        {
            tmp += val % 10 + '0';
            val /= 10;
        }
        for (int i = 0,j = tmp.length() -1; i < tmp.length(); i++,j--)
        {
            str_val += tmp[j];
        }
        str_val += '#';
    }
    void BST_preorder(TreeNode *node,string &data)
    {
        if(!node)
            return;
        string str_val;
        change_int_to_string(node->val,str_val);
        data.append(str_val);
        BST_preorder(node->left,data);
        BST_preorder(node->right,data);
    }
    void BST_insert(TreeNode *node,TreeNode * insert_node)
    {
        if(insert_node->val < node->val)
        {
            if(node->left)
            {
                BST_insert(node->left,insert_node);
            }
            else
            {
                node->left = insert_node;
            }

        }         
        else
        {
            if(node->right)
            {
                BST_insert(node->right,insert_node);
            }
            else
            {
                node->right = insert_node;
            }
        }
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string encodeData;
        BST_preorder(root,encodeData);
        return encodeData;
    }


    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty())
            return nullptr;
        vector<TreeNode*> vecNode;
        
        int val = 0;
        for (int i = 0; i < data.length(); i++)
        {
            if('#' == data[i])
            {
                vecNode.push_back(new TreeNode(val));
                val = 0;
            }   
            else
            {
                val = val * 10 + data[i] - '0';
            }
        }
        for (int i = 1; i < vecNode.size(); i++)
        {
            BST_insert(vecNode[0],vecNode[i]);
        }
        return vecNode[0];
        
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
// @lc code=end

