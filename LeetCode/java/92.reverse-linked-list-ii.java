/*
 * @lc app=leetcode id=92 lang=java
 *
 * [92] Reverse Linked List II
 */

// @lc code=start
/**
 * Definition for singly-linked list. public class ListNode { int val; ListNode
 * next; ListNode() {} ListNode(int val) { this.val = val; } ListNode(int val,
 * ListNode next) { this.val = val; this.next = next; } }
 */
class Solution {
    public ListNode reverseBetween(ListNode head, int m, int n) {
        if (head == null || m <= 0 || n <= 0)
            return head;
        ListNode dummy = new ListNode(0);
        dummy.next = head;

        ListNode prev = dummy;
        for (int i = 0; i < m - 1; ++i)
            prev = prev.next;

        ListNode partHead = prev.next, rest = prev.next;

        for (int i = 0; i < n - m + 1; ++i)
            rest = rest.next;
        prev.next = rest;

        for (int i = 0; i < n - m + 1; ++i) {
            ListNode tmp = partHead.next;
            partHead.next = prev.next;
            prev.next = partHead;
            partHead = tmp;
        }
        return dummy.next;
    }
}

class Solution {
    public ListNode reverseBetween(ListNode head, int m, int n) {
        if (head == null || m <= 0 || n <= 0)
            return head;
        ListNode dummy = new ListNode(0);
        dummy.next = head;

        ListNode prev = dummy;
        for (int i = 0; i < m - 1; ++i)
            prev = prev.next;
        ListNode tail = prev.next, rest = tail.next;
        for (int i = 0; i < n - m; ++i) {
            tail.next = rest.next;
            rest.next = prev.next;
            prev.next = rest;
            rest = tail.next;
        }
        return dummy.next;
    }
}
// @lc code=end
