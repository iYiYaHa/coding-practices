/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public int[] reversePrint(ListNode head) {
        List<Integer> res = new LinkedList<>();
        reverseConstructList(head, res);
        int[] arrayRes = new int[res.size()];
        int pos = 0;
        for(Integer val:res){
            arrayRes[pos++] = val;
        }
        return arrayRes;
    }

    private void reverseConstructList(ListNode head, List<Integer> res){
        if(head == null)return;
        reverseConstructList(head.next, res);
        res.add(head.val);
    }
}