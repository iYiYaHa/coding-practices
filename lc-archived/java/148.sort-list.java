/*
 * @lc app=leetcode id=148 lang=java
 *
 * [148] Sort List
 *
 * https://leetcode.com/problems/sort-list/description/
 *
 * algorithms
 * Medium (41.69%)
 * Likes:    3052
 * Dislikes: 140
 * Total Accepted:    281.2K
 * Total Submissions: 654.3K
 * Testcase Example:  '[4,2,1,3]'
 *
 * Sort a linked list in O(n log n) time using constant space complexity.
 * 
 * Example 1:
 * 
 * 
 * Input: 4->2->1->3
 * Output: 1->2->3->4
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: -1->5->3->4->0
 * Output: -1->0->3->4->5
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
    public ListNode sortList(ListNode head) {
        return mergeSortList(head);
    }
    private ListNode mergeSortList(ListNode head){
        if(head == null||head.next == null)
            return head;
        ListNode dummy = new ListNode(0,head);
        ListNode slow = dummy, fast = head;
        while(fast!=null && fast.next != null){
            slow = slow.next;
            fast = fast.next.next;
        }
        fast = slow.next;
        slow.next = null;
        ListNode left = mergeSortList(head);
        ListNode right = mergeSortList(fast);
        ListNode merged = mergeList(left,right);
        return merged;
    }

    private ListNode mergeList(ListNode left, ListNode right){
        if(left == null)
            return right;
        if(right == null)
            return left;
        if(left.val<=right.val){
            left.next=mergeList(left.next, right);
            return left;
        }else{
            right.next=mergeList(left, right.next);
            return right;
        }
    }
}
// @lc code=end

