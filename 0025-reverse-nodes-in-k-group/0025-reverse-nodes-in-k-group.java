class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        if (head == null || k == 1) {
            return head;
        }

        ListNode ans = null;
        ListNode prevGroupTail = null;
        ListNode temp = head;
        ListNode curr = head;

        int count = 0;

        while (curr != null) {
            count++;

            if (count == k) {
                ListNode next = curr.next;

                // Save the tail of this group
                ListNode groupTail = temp;

                // Detach group
                curr.next = null;

                // Reverse group
                ListNode newHead = reverse(temp);

                // First group
                if (ans == null) {
                    ans = newHead;
                } else {
                    // Connect previous group to current group
                    prevGroupTail.next = newHead;
                }

                // Tail of reversed group points to remaining list
                groupTail.next = next;

                // This becomes previous group's tail
                prevGroupTail = groupTail;

                // Move to next group
                temp = next;
                curr = next;
                count = 0;
            } else {
                curr = curr.next;
            }
        }

        return ans;
    }

    private ListNode reverse(ListNode head) {
        ListNode prev = null;
        ListNode curr = head;

        while (curr != null) {
            ListNode next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
}