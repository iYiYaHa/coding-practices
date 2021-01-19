/*
 * @lc app=leetcode id=86 lang=java
 *
 * [86] Partition List
 *
 * https://leetcode.com/problems/partition-list/description/
 *
 * algorithms
 * Medium (41.08%)
 * Likes:    1772
 * Dislikes: 354
 * Total Accepted:    243.8K
 * Total Submissions: 566.7K
 * Testcase Example:  '[1,4,3,2,5,2]\n3'
 *
 * Given the head of a linked list and a value x, partition it such that all
 * nodes less than x come before nodes greater than or equal to x.
 * 
 * You should preserve the original relative order of the nodes in each of the
 * two partitions.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: head = [1,4,3,2,5,2], x = 3
 * Output: [1,2,2,4,3,5]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: head = [2,1], x = 2
 * Output: [1,2]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [0, 200].
 * -100 <= Node.val <= 100
 * -200 <= x <= 200
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
    public ListNode partition(ListNode head, int x) {
        if (head == null)
            return null;
        ListNode dummyLt = new ListNode();
        ListNode dummyGt = new ListNode();
        ListNode lt = dummyLt, gt = dummyGt;

        while (head != null) {
            ListNode rest = head.next;
            if (head.val < x) {
                lt.next = head;
                lt = lt.next;
            } else {
                gt.next = head;
                gt = gt.next;
            }
            head = rest;
        }
        lt.next = dummyGt.next;
        gt.next = null;
        return dummyLt.next;
    }
}
// @lc code=end
