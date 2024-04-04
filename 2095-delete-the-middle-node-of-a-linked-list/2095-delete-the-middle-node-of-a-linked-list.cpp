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
    ListNode* deleteMiddle(ListNode* head) {
        int n = 0;
        ListNode* temp = head;
        while(temp) {
            n++;
            temp = temp->next;
        }
        
        if(n == 1)
            return nullptr;
        
        n /= 2;
        
        temp = head;
        while(n > 1) {
            temp = temp->next;
            n--;
        }
        
        temp->next = temp->next->next;
        
        return head;
    }
};