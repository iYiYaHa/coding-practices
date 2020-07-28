/*
 * @lc app=leetcode id=143 lang=java
 *
 * [143] Reorder List
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
    public void reorderList(ListNode head) {
        if(head == null)
            return;

        // Find the start of the right half
        ListNode slow = head, fast = head;
        while(fast != null && fast.next != null){
            slow = slow.next;
            fast = fast.next.next;
        }

        // Reverse the right half with stack.
        LinkedList<ListNode> stack = new LinkedList<>();
        ListNode tmp = slow.next;
        slow.next = null;
        slow = tmp;
        while(slow!=null){
            stack.addLast(slow);
            slow = slow.next;
        }

        ListNode cur = head;
        while(!stack.isEmpty()){
            ListNode ele = stack.removeLast();
            ele.next = cur.next;
            cur.next = ele;
            cur = ele.next;
        }
    }
}
// @lc code=end

