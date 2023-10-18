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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==NULL)
            return NULL;

        ListNode* prev = head;
        ListNode* curr = head;
        int step = 0;
        while(curr!=NULL) {
            curr = curr->next;
            if(step>n)
                prev = prev->next;
            step++;
        }
        if(n==step) 
            return head->next;
        if(n==1)
            prev->next = NULL;
        else 
            prev->next = prev->next->next;
        return head;
    }
};