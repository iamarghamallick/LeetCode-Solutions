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
    public int pairSum(ListNode head) {
        int n = 0;
        ListNode temp = head;
        while(temp != null) {
            temp = temp.next;
            n++;
        }
        ListNode rightHead = head;
        n /= 2;
        while(n > 0) {
            rightHead = rightHead.next;
            n--;
        }

        // reverse the right half
        ListNode curr = rightHead;
        ListNode prev = null;
        ListNode next;
        while(curr != null) {
            next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }
        rightHead = prev;
        int sum = 0;
        while(rightHead != null) {
            sum = Math.max(sum, head.val + rightHead.val);
            head = head.next;
            rightHead = rightHead.next;
        }

        return sum;
    }
}