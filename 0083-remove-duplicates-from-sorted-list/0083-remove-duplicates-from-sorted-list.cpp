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
    ListNode* deleteDuplicates(ListNode* head) {
        set<int> s;
        ListNode* curr = head;
        ListNode* prev = head;
        while(curr != NULL) {
            if(s.find(curr->val) != s.end()) {
                // found in the set
                prev->next = curr->next;
            } else {
                s.insert(curr->val);
                prev = curr;
            }
            curr = curr->next;
        }
        return head;
    }
};