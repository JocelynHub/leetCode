/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
 * 思路一：将K个链表一个一个的连上去，时间复杂度比较大
 * 思路二：将这些节点放到vector中，再调用排序函数
 * 思路三：分制方法，两两之后 再 两两
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
//思路二：
// #include <vector>
// #include <algorithm>
// bool cmp(const ListNode *a,const ListNode *b)
// {
//     return a->val<b->val;
// }
// class Solution {
// public:
//     ListNode* mergeKLists(std::vector<ListNode*>& lists) {
//         std::vector<ListNode*> node_vec;
//         for (int i = 0; i < lists.size(); i++)
//         {
//             ListNode *head = lists[i];
//             while(head)
//             {
//                 node_vec.push_back(head);
//                 head = head->next;
//             }
//         }
//         if(node_vec.empty())
//             return nullptr;
//         std::sort(node_vec.begin(),node_vec.end(),cmp);
//         //注意这里有问题，用下面注释掉的会出现问题
//         for (int i = 1; i < node_vec.size(); i++)
//         {
//             node_vec[i-1]->next = node_vec[i];
//         }

//         // for (int i = 0; i < node_vec.size(); i++)
//         // {
//         //     node_vec[i]->next = node_vec[i+1];
//         // }
//         node_vec[node_vec.size()-1]->next = nullptr;
//         return node_vec[0];
        
           
//     }
// };
//思路三 分制方法
#include <vector>


class Solution {
public:
    ListNode *mergeTwoList(ListNode*l1,ListNode *l2)
    {
        ListNode temp_head(0);
        ListNode *ptr = &temp_head;
        while(l1 && l2)
        {
            if(l1->val < l2->val)
            {
                ptr->next = l1;
                l1 = l1->next;
            }
            else
            {
                ptr->next = l2;
                l2 = l2->next;
            }
            ptr = ptr->next;
        }
        if(l1)
        {
            ptr->next = l1;
        }
        if(l2)
        {
            ptr->next = l2;
        }
        return temp_head.next;
    }



    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        if(lists.empty())
            return nullptr;
        if(lists.size() == 1)
            return lists[0];
        if(lists.size() == 2)
            return mergeTwoList(lists[0],lists[1]);
        
        int mid = lists.size() / 2;
        std::vector<ListNode*> sub_list1;
        std::vector<ListNode*> sub_list2;
        for (int i = 0; i < mid; i++)
        {
            sub_list1.push_back(lists[i]);
        }
        for (int i = mid; i < lists.size(); i++)
        {
            sub_list2.push_back(lists[i]);
        }
        ListNode * l1 = mergeKLists(sub_list1);
        ListNode * l2 = mergeKLists(sub_list2);
        return mergeTwoList(l1,l2);
        
        
    }
};

// @lc code=end

