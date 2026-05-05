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
    public ListNode rotateRight(ListNode head, int k) {
        int n = 0;
        ListNode temp = head;
        while(temp != null) {
            n++;
            temp = temp.next;
        }

        if(head == null || n <= 1) {
            return head;
        }

        k %= n;

        if(k == 0) {
            return head;
        }

        k = n - k;

        ListNode prev = head;
        while(k > 1) {
            prev = prev.next;
            k--;
        }

        ListNode newHead = prev.next;
        prev.next = null;

        temp = newHead;
        while(temp != null && temp.next != null) {
            temp = temp.next;
        }

        temp.next = head;

        return newHead;
    }
}