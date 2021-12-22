/*
 * @lc app=leetcode id=142 lang=cpp
 *
 * [142] Linked List Cycle II
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
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
    if (!head || !head->next || !head->next->next) return NULL;
        while(fast!=NULL && fast->next!=NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
            if(fast==slow)
            {
                break;
            }
            
        }
        if(fast!=slow)
        {
            return NULL;
        }
        fast = head;
        while(fast!=slow)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};
// @lc code=end

