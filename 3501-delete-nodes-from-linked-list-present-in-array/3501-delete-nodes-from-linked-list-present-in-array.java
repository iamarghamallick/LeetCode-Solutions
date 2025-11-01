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
    public ListNode modifiedList(int[] nums, ListNode head) {
        HashSet<Integer> set = new HashSet<>();
        for(int num: nums) set.add(num);

        ListNode prev = head;
        ListNode curr = head;
        while(curr != null) {
            if(set.contains(curr.val)) {
                if(curr == head) {
                    head = curr.next;
                    prev = curr.next;
                } else 
                    prev.next = curr.next;
            } else 
                prev = curr;
            curr = curr.next;
        }

        return head;
    }
}