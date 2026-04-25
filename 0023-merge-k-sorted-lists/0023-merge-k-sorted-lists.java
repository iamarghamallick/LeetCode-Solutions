/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        int k = lists.length;

        if(k == 0) {
            return null;
        } 
        if(k == 1) {
            return lists[0];
        }

        ListNode ans = lists[0];

        for(int i=1; i<k; i++) {
            ans = merge2Lists(ans, lists[i]);
        }

        return ans;
    }

    private ListNode merge2Lists(ListNode list1, ListNode list2) {
        ListNode dummy = new ListNode(-1);
        ListNode temp = dummy;

        while (list1 != null && list2 != null) {
            if (list1.val <= list2.val) {
                temp.next = list1;
                list1 = list1.next;
            } else {
                temp.next = list2;
                list2 = list2.next;
            }
            temp = temp.next;
        }
        
        temp.next = (list1 != null) ? list1 : list2;

        return dummy.next;
    }
}