/*
 * @lc app=leetcode id=82 lang=java
 *
 * [82] Remove Duplicates from Sorted List II
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/
 *
 * algorithms
 * Medium (36.45%)
 * Likes:    1927
 * Dislikes: 111
 * Total Accepted:    264.7K
 * Total Submissions: 711.5K
 * Testcase Example:  '[1,2,3,3,4,4,5]'
 *
 * Given a sorted linked list, delete all nodes that have duplicate numbers,
 * leaving only distinct numbers from the original list.
 * 
 * Return the linked list sorted as well.
 * 
 * Example 1:
 * 
 * 
 * Input: 1->2->3->3->4->4->5
 * Output: 1->2->5
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 1->1->1->2->3
 * Output: 2->3
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
    public ListNode deleteDuplicates(ListNode head) {
        if (head == null || head.next == null)
            return head;
        ListNode dummy = new ListNode(0);
        ListNode prev = dummy;
        ListNode tail = head;
        while (tail != null) {
            if (tail.next != null && tail.next.val == tail.val) {
                tail = tail.next;
            } else {
                if (head == tail) {
                    prev.next = head;
                    prev = head;
                } 
                tail = tail.next;
                head = tail;
                prev.next = null;
            }
        }
        return dummy.next;
    }
}

class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        if (head == null || head.next == null)
            return head;
        ListNode tail = head;
        if(tail.next.val == tail.val){
            while(tail.next != null && tail.val == tail.next.val){
                tail = tail.next;
            }
            return deleteDuplicates(tail.next);
        }else{
            head.next = deleteDuplicates(head.next);
            return head;
        }
    }
}
// @lc code=end

