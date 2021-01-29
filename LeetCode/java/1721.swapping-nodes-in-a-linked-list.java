/*
 * @lc app=leetcode id=1721 lang=java
 *
 * [1721] Swapping Nodes in a Linked List
 *
 * https://leetcode.com/problems/swapping-nodes-in-a-linked-list/description/
 *
 * algorithms
 * Medium (65.21%)
 * Likes:    140
 * Dislikes: 14
 * Total Accepted:    12.3K
 * Total Submissions: 18.8K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * You are given the head of a linked list, and an integer k.
 * 
 * Return the head of the linked list after swapping the values of the k^th
 * node from the beginning and the k^th node from the end (the list is
 * 1-indexed).
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: head = [1,2,3,4,5], k = 2
 * Output: [1,4,3,2,5]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: head = [7,9,6,6,7,8,3,0,9,5], k = 5
 * Output: [7,9,6,6,8,7,3,0,9,5]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: head = [1], k = 1
 * Output: [1]
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: head = [1,2], k = 1
 * Output: [2,1]
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: head = [1,2,3], k = 2
 * Output: [1,2,3]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the list is n.
 * 1 <= k <= n <= 10^5
 * 0 <= Node.val <= 100
 * 
 * 
 */

// @lc code=start
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
    public ListNode swapNodes(ListNode head, int k) {
        ListNode node1 = null;
        ListNode node2 = null;
        for(ListNode cur = head; cur != null; cur = cur.next){
            node2 = node2 == null ? null : node2.next;
            if(--k == 0){
                node1 = cur;
                node2 = head;
            }
        }
        int tmp = node1.val;
        node1.val = node2.val;
        node2.val = tmp;
        return head;
    }
}

ß
// @lc code=end
