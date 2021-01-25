/*
 * @lc app=leetcode id=61 lang=java
 *
 * [61] Rotate List
 *
 * https://leetcode.com/problems/rotate-list/description/
 *
 * algorithms
 * Medium (29.76%)
 * Likes:    2000
 * Dislikes: 1115
 * Total Accepted:    347.4K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given the head of a linked list, rotate the list to the right by k
 * places.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: head = [1,2,3,4,5], k = 2
 * Output: [4,5,1,2,3]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: head = [0,1,2], k = 4
 * Output: [2,0,1]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the list is in the range [0, 500].
 * -100 <= Node.val <= 100
 * 0 <= k <= 2 * 10^9
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
    // Connect the head node and the tail node
    // And cut from the new tail.

    public ListNode rotateRight(ListNode head, int k) {
        if (head == null || k <= 0)
            return head;
        ListNode cur = head;
        int len = 1;
        while (cur.next != null) {
            cur = cur.next;
            ++len;
        }
        cur.next = head;

        k = k % len;

        ListNode res = head;
        cur = head;
        for (int i = 1; i < len - k; ++i) {
            cur = cur.next;
        }
        res = cur.next;
        cur.next = null;
        return res;
    }
}
// @lc code=end
