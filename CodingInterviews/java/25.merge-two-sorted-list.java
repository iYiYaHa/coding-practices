/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if(l1 == null) return l2;
        if(l2 == null) return l1;
        if(l1.val <= l2.val){
            l1.next = mergeTwoLists(l1.next, l2);
            return l1;
        }else{
            l2.next = mergeTwoLists(l1, l2.next);
            return l2;
        }
    }
}

class SolutionB {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode(0);
        ListNode tail = dummy;
        while(l1 != null && l2 != null){
            ListNode cur;
            if(l1.val <= l2.val){
                cur = l1;
                l1 = l1.next;
            }else{
                cur = l2;
                l2 = l2.next;
            }
            tail.next = cur;
            tail = cur;
        }
        tail.next = l1!=null ? l1:l2;
        return dummy.next;
    }
}