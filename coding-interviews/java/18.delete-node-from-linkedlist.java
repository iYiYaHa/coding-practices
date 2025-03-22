/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode deleteNode(ListNode head, int val) {
        ListNode dummy = new ListNode(0);
        dummy.next=head;
        ListNode prev = dummy, cur = dummy.next;
        while(cur != null && cur.val != val){
            prev = prev.next;
            cur = cur.next;
        }
        if(cur != null){
            prev.next=cur.next;
        }
        return dummy.next;
    }
}