/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
 * 思路：
 * 利用临时头节点
 * 分别在ListNode less_head(0) ListNode more_head(0) 后面归类
 * 最后再将两个连起来
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
    ListNode* partition(ListNode* head, int x) {
        ListNode less_head(0);
        ListNode more_head(0);
        ListNode* lessPtr = &less_head;
        ListNode* morePtr = &more_head;
        while(head)
        {
            if(head->val < x){
                lessPtr->next = head;//把这个节点插到 lessPtr后面
                lessPtr = head;//连接完成后，lessPtr向后移动，指向head
            }
            else
            {
                morePtr->next = head;
                morePtr = head;
            }
            head = head->next;
            
        }
        lessPtr->next = more_head.next;//less链尾与 more链表头相连
        morePtr->next = nullptr;//将morePtr即链表尾结点置空
        return less_head.next;//返回的是临时头节点的下一个
        
    }
};
// @lc code=end

