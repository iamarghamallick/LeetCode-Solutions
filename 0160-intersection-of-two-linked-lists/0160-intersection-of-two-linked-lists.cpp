/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> set;
        ListNode* temp = headA;
        while(temp) {
            set.insert(temp);
            temp = temp->next;
        }
        
        temp = headB;
        while(temp) {
            if(set.count(temp))
                return temp;
            temp = temp->next;
        }

        return nullptr;
    }
};