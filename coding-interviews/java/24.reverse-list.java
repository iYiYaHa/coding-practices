/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class SolutionA {
    public ListNode reverseList(ListNode head) {
        if(head == null || head.next == null)
            return head;
        ListNode reversedHead = reverseList(head.next);
        head.next.next = head;
        head.next = null;
        return reversedHead;
    }
}

class SolutionB {
    public ListNode reverseList(ListNode head) {
        ListNode dummy = new ListNode(0);
        while(head != null){
            ListNode cur = head;
            head = head.next;
            cur.next = dummy.next;
            dummy.next = cur;
        }
        return dummy.next;
    }
}