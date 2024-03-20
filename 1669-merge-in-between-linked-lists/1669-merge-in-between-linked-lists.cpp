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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        b -= a;
        
        while(a > 1) {
            temp1 = temp1->next;
            a--;
        }
        
        ListNode* temp3 = temp1->next;
        
        temp1->next = list2;
        
        while(b > 0) {
            temp3 = temp3->next;
            b--;
        }
        
        temp3 = temp3->next;
        
        while(temp2->next) {
            temp2 = temp2->next;
        }
        temp2->next = temp3;
        
        return list1;
    }
};