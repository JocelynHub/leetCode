/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 * 思路1.将其中一个链表放到set中，然后遍历另一个链表，如果在set中找到了当下浮动链表，即为第一个交点
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
//时间复杂度O(N*log(N)) 空间复杂度O(N) set的原因
// #include <set>
// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         std::set<ListNode*> node_set;
//         while(headA)
//         {
//             node_set.insert(headA);
//             headA = headA->next;
//         }
//         while(headB){
//             if(node_set.find(headB) != node_set.end())
//             {
//                 return headB;
//             }
//             headB = headB->next;
//         }
//         return nullptr;
        
//     }
// };

//思路2
//时间复杂度为O(N) 空间复杂度为O(1)
//计算两个链表的长度，较长的链表多出来的长度
//将较长链表的指针移动到较短指针链表对齐的位置，较长的先走
//对齐后一起走，当两个指针指向同一个地址，即为第一个节点
#include <set>
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = get_list_length(headA);
        int lenB = get_list_length(headB);
        if(lenA > lenB)
            headA = forward_long_list(lenA,lenB,headA);
        else 
        {
            headB = forward_long_list(lenB,lenA,headB);
        }
        while(headA && headB)
        {
            if(headA == headB)
                return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return nullptr;
        
    }
    int get_list_length(ListNode *head){
        int len = 0;
        while(head)
        {
            len++;
            head = head->next;
        }
        return len;
    }
    ListNode *forward_long_list(int longLen,int shortLen,ListNode *headShouldMove)
    {
        int deltaLen = longLen - shortLen;
        while(headShouldMove && deltaLen)
        {
            headShouldMove = headShouldMove->next;
            deltaLen--;
        }
        return headShouldMove;
    }
};
// @lc code=end

