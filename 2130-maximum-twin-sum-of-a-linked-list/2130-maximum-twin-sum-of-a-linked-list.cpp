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
    int pairSum(ListNode* head) {
        vector<int> a;
        while(head) {
            a.push_back(head->val);
            head = head->next;
        }
        
        int ans = INT_MIN;
        int n = a.size();
        for(int i=0; i<n/2; i++)
            ans = max(ans, a[i] + a[n-1-i]);
        
        return ans;
    }
};