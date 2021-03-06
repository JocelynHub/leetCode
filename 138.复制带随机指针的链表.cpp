/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 复制带随机指针的链表
 * 思路：
 * 复杂链表的深度拷贝
 * 利用map
 * std::map<RandomListNode*,int> 来定义指向关系
 * 因为有指针 需要深度拷贝 所以需要知道新链表中 随机指针指向的新地址是什么
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
#include<map>
#include <vector>
class Solution {
public:
    Node* copyRandomList(Node* head) {
        std::map<Node*,int> node_map;
        std::vector<Node*> node_vec; //新链表可以认为是个数组
        Node* ptr = head;//方便访问 重新访问
        int i= 0;//对应的节点ID
        while(ptr)//因为动的是ptr 不是head
        {
            node_vec.push_back(new Node(ptr->val));
            node_map[ptr] = i;//将原始链表地址 和 节点Id对应起来
            ptr = ptr->next;
            i++;
        }
        node_vec.push_back(nullptr);

        ptr = head;
        i = 0;
        while(ptr)
        {
            node_vec[i]->next = node_vec[i+1];//将新链表连接起来
            if(ptr->random)
            {
                int id = node_map[ptr->random];//ptr->random肯定存在，因为原链表存在 ptr 和 i同时进行 保证了对应关系 0号还是0号，先看54 再看53
                node_vec[i]->random = node_vec[id];//右侧肯定是node_vec
            }
            ptr = ptr->next;
            i++;
        }
        return node_vec[0];
    }
};
// @lc code=end

