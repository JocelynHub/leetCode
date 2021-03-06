/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 * 在每个Node的地方翻转
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
//  struct ListNode {
//       int val;
//       ListNode *next;
//       ListNode(int x) : val(x), next(nullptr) {}
//   };
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *newHead = nullptr;
        while(head){
            //备份当前head的next
            ListNode *next = head->next;
            //更新head的next
            head->next = newHead;
            //移动head和newHead
            newHead = head;
            head = next;
        }
        return newHead;
    }
};
// @lc code=end

