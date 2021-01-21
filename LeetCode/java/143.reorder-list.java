/*
 * @lc app=leetcode id=143 lang=java
 *
 * [143] Reorder List
 */

// @lc code=start
/**
 * Definition for singly-linked list. public class ListNode { int val; ListNode
 * next; ListNode() {} ListNode(int val) { this.val = val; } ListNode(int val,
 * ListNode next) { this.val = val; this.next = next; } }
 */
class Solution {
    public void reorderList(ListNode head) {
        if (head == null)
            return;

        // Find the start of the right half
        ListNode slow = head, fast = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }

        // Reverse the right half with stack.
        LinkedList<ListNode> stack = new LinkedList<>();
        ListNode tmp = slow.next;
        slow.next = null;
        slow = tmp;
        while (slow != null) {
            stack.addLast(slow);
            slow = slow.next;
        }

        ListNode cur = head;
        while (!stack.isEmpty()) {
            ListNode ele = stack.removeLast();
            ele.next = cur.next;
            cur.next = ele;
            cur = ele.next;
        }
    }
}

class Solution {
    public void reorderList(ListNode head) {
        if (head == null || head.next == null)
            return;
        ListNode mid = findMidAndCut(head);
        ListNode reverseRightHalf = reverseList(mid);

        ListNode cur = reverseRightHalf;
        while (head != null && cur != null) {
            ListNode rest = cur.next;
            cur.next = head.next;
            head.next = cur;
            head = cur.next;
            cur = rest;
        }
    }

    private ListNode findMidAndCut(ListNode head) {
        if (head == null)
            return null;
        ListNode slow = head, fast = head.next;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        ListNode mid = slow.next;
        slow.next = null;
        return mid;
    }

    private ListNode reverseList(ListNode head) {
        if (head == null)
            return null;
        ListNode dummy = new ListNode();
        while (head != null) {
            ListNode rest = head.next;
            head.next = dummy.next;
            dummy.next = head;
            head = rest;
        }
        return dummy.next;
    }
}
// @lc code=end
