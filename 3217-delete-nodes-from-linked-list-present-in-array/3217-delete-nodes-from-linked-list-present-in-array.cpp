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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> set(nums.begin(), nums.end());
        
        while(head && set.find(head->val) != set.end())
            head = head->next;
        
        if(!head)
            return nullptr;
        
        ListNode* curr = head;
        while(curr->next) {
            int num = curr->next->val;
            if(set.find(num) != set.end()) {
                curr->next = curr->next->next;
            } else {
                curr = curr->next;
            }
        }
        
        return head;
    }
};