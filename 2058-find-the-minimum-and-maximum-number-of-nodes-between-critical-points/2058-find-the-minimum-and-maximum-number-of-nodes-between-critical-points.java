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
    public int[] nodesBetweenCriticalPoints(ListNode head) {
        int[] ans = new int[] { Integer.MAX_VALUE, Integer.MIN_VALUE }; // [minDist, maxDist]

        ListNode prev = head;
        ListNode curr = head.next;
        ListNode next = curr.next;

        if (next == null) {
            return new int[] { -1, -1 };
        }

        boolean found = false;
        int distFromFirst = 0;
        int distFromPrev = 0;

        while (next != null) {
            if (found) {
                distFromFirst++;
                distFromPrev++;
            }
            if (isCritical(prev.val, curr.val, next.val)) {
                if (found) {
                    ans[0] = Math.min(ans[0], distFromPrev);
                    ans[1] = Math.max(ans[1], distFromFirst);
                    distFromPrev = 0;
                } else {
                    found = true;
                }
            }

            prev = curr;
            curr = next;
            next = next.next;
        }

        if (ans[0] == Integer.MAX_VALUE || ans[1] == Integer.MIN_VALUE) {
            return new int[] { -1, -1 };
        }

        return ans;
    }

    private boolean isCritical(int prev, int curr, int next) {
        if ((curr < prev && curr < next) ||
                (curr > prev && curr > next)) {
            return true;
        }

        return false;
    }
}