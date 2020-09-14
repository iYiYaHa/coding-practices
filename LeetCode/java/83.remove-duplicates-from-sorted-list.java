/*
 * @lc app=leetcode id=83 lang=java
 *
 * [83] Remove Duplicates from Sorted List
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/
 *
 * algorithms
 * Easy (45.14%)
 * Likes:    1780
 * Dislikes: 122
 * Total Accepted:    493.1K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,1,2]'
 *
 * Given a sorted linked list, delete all duplicates such that each element
 * appear only once.
 * 
 * Example 1:
 * 
 * 
 * Input: 1->1->2
 * Output: 1->2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 1->1->2->3->3
 * Output: 1->2->3
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
    public ListNode deleteDuplicates(ListNode head) {
        if(head == null||head.next == null){
            return head;
        }
        ListNode dummy = new ListNode(0);
        ListNode prev = dummy, tail = head;
        while(tail != null){
            if(tail.next != null && tail.val == tail.next.val){
                tail = tail.next;
            }else{
                prev.next=head;
                prev = head;
                tail = tail.next;
                head = tail;
                prev.next = null;
            }
        }
        return dummy.next;
    }
}
// @lc code=end
