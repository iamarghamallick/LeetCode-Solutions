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
    ListNode* reverse(ListNode* head) {
        ListNode* curr = head;
        ListNode *prev = NULL, *next = NULL;

        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
        return head;
    }
    
    ListNode* doubleIt(ListNode* head) {
        head = reverse(head);
        ListNode* ans = nullptr;
        int carry = 0;
        
        while(head) {
            int sum = head->val + head->val + carry;
            ListNode* nn = new ListNode(sum % 10);
            if(!ans)    ans = nn;
            else {
                nn->next = ans;
                ans = nn;
            }
            carry = sum / 10;
            head = head->next;
        }
        
        while(carry) {
            ListNode* nn = new ListNode(carry % 10);
            nn->next = ans;
            ans = nn;
            carry /= 10;
        }
        
        return ans;
    }
};