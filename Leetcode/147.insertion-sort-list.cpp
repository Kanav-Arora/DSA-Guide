/*
 * @lc app=leetcode id=147 lang=cpp
 *
 * [147] Insertion Sort List
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
class Solution {
public:
    ListNode* sorted;
    void sortedInsert(ListNode* newnode)
    {
        if(sorted==NULL || sorted->val >= newnode->val)
        {
            newnode->next = sorted;
            sorted = newnode;
        }
        else
        {
            ListNode* current = sorted;
            while(current->next!=NULL && current->next->val < newnode->val)
            {
                current = current->next;
            }
            newnode->next = current->next;
            current->next = newnode;
        }
    }

    ListNode* insertionSortList(ListNode* head) {
        sorted= NULL;
        ListNode* current = head;
        while(current!=NULL)
        {
            ListNode* next = current->next;
            sortedInsert(current);
            current = next;
        }
        head= sorted;
        return sorted;
        
    }
};
// @lc code=end

