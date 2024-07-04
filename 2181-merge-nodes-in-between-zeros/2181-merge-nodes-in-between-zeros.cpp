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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* ans = nullptr, *temp = nullptr;
        ListNode* curr = head;
        int sum = 0;
        
        while(curr) {
            if(curr->val == 0 && sum > 0) {
                insert(ans, temp, sum);
                sum = 0;
            } else {
                sum += curr->val;
            }
            curr = curr->next;
        }
        
        return ans;
    }

private:
    void insert(ListNode* &ans, ListNode* &temp, int val) {
        if(!ans) {
            ans = new ListNode(val);
            temp = ans;
        } else {
            temp->next = new ListNode(val);
            temp = temp->next;
        }
    }
};