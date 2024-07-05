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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> arr;
        ListNode* prev = head, *curr = head->next;
        int index = 1;
        while(curr && curr->next) {
            if(curr->val > prev->val && curr->val > curr->next->val)
                // local maxima
                arr.push_back(index);
            else if(curr->val < prev->val && curr->val < curr->next->val)
                // local minima
                arr.push_back(index);
            
            prev = curr;
            curr = curr->next;
            index++;
        }
        
        int n = arr.size();
        if(n < 2)
            return {-1, -1};
        int maxDist = arr[n-1] - arr[0];
        int minDist = INT_MAX;
        for(int i=1; i<n; i++)
            minDist = min(minDist, arr[i] - arr[i-1]);
        
        return {minDist, maxDist};
    }
};