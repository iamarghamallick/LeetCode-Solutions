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
    void addNode(ListNode* &currHead, ListNode* &temp, int val) {
        if(!currHead) {
            currHead = new ListNode(val);
            temp = currHead;
        } else {
            temp->next = new ListNode(val);
            temp = temp->next;
        }
    }
    
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        ListNode* curr = head;
        while(curr) {
            n++;
            curr = curr->next;
        }
        
        vector<ListNode*> ans(k);
        int index = 0;
        int size = n / k;
        int extra = n % k;
        
        while(head) {
            ListNode* currHead = nullptr, *temp = nullptr;
            while(size) {
                addNode(currHead, temp, head->val);
                size--;
                head = head->next;
            }
            if(extra) {
                addNode(currHead, temp, head->val);
                extra--;
                head = head->next;
            }
            ans[index++] = currHead;
            size = n / k;
        }
        
        return ans;
    }
};