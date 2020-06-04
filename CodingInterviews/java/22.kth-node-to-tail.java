/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode getKthFromEnd(ListNode head, int k) {
        if(head == null || k <= 0)
            return null;

        ListNode slow = head, fast = head;
        for(int i = 0;i < k;++i){
            if(fast == null){
                return null;
            }else{
                fast = fast.next;
            }
        }
        while(fast != null){
            slow = slow.next;
            fast = fast.next;
        }
        return slow;
    }
}