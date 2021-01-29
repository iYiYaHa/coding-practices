/*
 * @lc app=leetcode id=445 lang=java
 *
 * [445] Add Two Numbers II
 *
 * https://leetcode.com/problems/add-two-numbers-ii/description/
 *
 * algorithms
 * Medium (56.09%)
 * Likes:    2098
 * Dislikes: 194
 * Total Accepted:    216.5K
 * Total Submissions: 385.9K
 * Testcase Example:  '[7,2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The most significant digit comes first and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 * 
 * Follow up:
 * What if you cannot modify the input lists? In other words, reversing the
 * lists is not allowed.
 * 
 * 
 * 
 * Example:
 * 
 * Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 8 -> 0 -> 7
 * 
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list. public class ListNode { int val; ListNode
 * next; ListNode() {} ListNode(int val) { this.val = val; } ListNode(int val,
 * ListNode next) { this.val = val; this.next = next; } }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        LinkedList<Integer> stack1 = putInStack(l1);
        LinkedList<Integer> stack2 = putInStack(l2);
        ListNode dummy = new ListNode();
        int carry = 0;
        while (!stack1.isEmpty() || !stack2.isEmpty() || carry != 0) {
            int val1 = stack1.isEmpty() ? 0 : stack1.pop();
            int val2 = stack2.isEmpty() ? 0 : stack2.pop();

            int sum = val1 + val2 + carry;
            carry = sum / 10;
            sum = sum % 10;

            ListNode node = new ListNode(sum);
            node.next = dummy.next;
            dummy.next = node;
        }
        return dummy.next;
    }

    private LinkedList<Integer> putInStack(ListNode head) {
        LinkedList<Integer> stack = new LinkedList<>();
        while (head != null) {
            stack.push(head.val);
            head = head.next;
        }
        return stack;
    }
}

class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int len1 = getListLen(l1);
        int len2 = getListLen(l2);
        ListNode dummy = new ListNode();
        while (len1 > 0 || len2 > 0) {
            int val1 = 0, val2 = 0;
            if (len1 >= len2) {
                val1 = l1 == null ? 0 : l1.val;
                l1 = l1.next;
                --len1;
            }
            if (len1 + 1 <= len2) {
                val2 = l2 == null ? 0 : l2.val;
                l2 = l2.next;
                --len2;
            }

            ListNode node = new ListNode(val1 + val2);
            node.next = dummy.next;
            dummy.next = node;
        }

        // Normalize the new list
        ListNode head = dummy.next;
        dummy.next = null;
        int carry = 0;
        while (head != null) {
            ListNode node = head;
            head = head.next;
            node.val = node.val + carry;
            carry = node.val / 10;
            node.val = node.val % 10;
            node.next = dummy.next;
            dummy.next = node;
        }
        if (carry != 0) {
            ListNode node = new ListNode(carry);
            node.next = dummy.next;
            dummy.next = node;
        }
        return dummy.next;
    }

    private int getListLen(ListNode head) {
        int len = 0;
        while (head != null) {
            ++len;
            head = head.next;
        }
        return len;
    }
}
// @lc code=end
