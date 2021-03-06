/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int changLen = n - m + 1;//需要逆置的节点个数
        ListNode *pre_head = nullptr;//初始化 逆置逆置节点前驱
        ListNode *result = head;//最终转换后的头节点，非特殊情况为head

        while(head && --m){
            pre_head = head;
            head = head->next;
        }
        ListNode *modify_list_tail = head;//逆置后的尾节点
        ListNode *new_head = nullptr;
        while(head && changLen)
        {
            ListNode *next = head->next;
            head->next = new_head;
            new_head = head;
            head = next;
            changLen--;
        }
        modify_list_tail->next = head;//逆置后链表尾和逆置段后一节点
        if(pre_head)
        {
            pre_head->next = new_head;//不是从第一个节点开始逆序的，将逆置 开始节点前驱 与逆置后头节点连接
        }
        else
        {
            result = new_head;
        }
        return result;

    }
};
// @lc code=end

