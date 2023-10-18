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
    ListNode* findMid(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next!=NULL && fast->next->next!=NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode* reverse(ListNode* head) {
        if(head==NULL || head->next==NULL) 
            return head;
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr!=NULL) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return true;

        ListNode* firstH = head;
        ListNode* mid = findMid(head);
        ListNode* lastH = reverse(mid->next);

        while(lastH != NULL) {
            if(firstH->val != lastH->val) {
                    return false;
            }
            firstH = firstH->next;
            lastH = lastH->next;
        }
        return true;
    }
};