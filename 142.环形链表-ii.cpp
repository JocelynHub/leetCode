/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 * 两个思路
 * 第一个使用set
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//思路1
// #include<set>
// class Solution {
// public:
//     ListNode *detectCycle(ListNode *head) {
//         std::set<ListNode*>node_set;
//         while(head){
//             if(node_set.find(head) != node_set.end())
//                 return head;
//             node_set.insert(head);
//             head = head->next;
//         }
//         return nullptr;
//     }
// };


//思路2
//快慢指针
//快指针 速度为慢指针的2倍
//两个相遇的地方，是快指针走过路程为慢指针2倍的地方
//但是这个地方，不是相遇的起点
//从公式推导，从head 和 meet 以相同的速度同时出发，相遇点就是 环的起点
#include<set>
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *meet = nullptr;
        while(fast)//需要一个循环 让两个链表走起来
        {
            fast = fast->next;
            slow = slow->next;
            if(!fast)
                return nullptr;
            fast = fast->next;

            if(fast == slow)
            {
                meet = fast;
                break;
            }

        }


        while(head && meet)
        {
            if(head == meet)
            {
                return head;
            }
            head = head->next;
            meet = meet->next;
        }
        return nullptr;
    }
};
// @lc code=end

