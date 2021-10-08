//Given a singly linked list, return a random node's value from the linked list.
// Each node must have the same probability of being chosen. 
//
// Implement the Solution class: 
//
// 
// Solution(ListNode head) Initializes the object with the integer array nums. 
// int getRandom() Chooses a node randomly from the list and returns its value. 
//All the nodes of the list should be equally likely to be choosen. 
// 
//
// 
// Example 1: 
//
// 
//Input
//["Solution", "getRandom", "getRandom", "getRandom", "getRandom", "getRandom"]
//[[[1, 2, 3]], [], [], [], [], []]
//Output
//[null, 1, 3, 2, 2, 3]
//
//Explanation
//Solution solution = new Solution([1, 2, 3]);
//solution.getRandom(); // return 1
//solution.getRandom(); // return 3
//solution.getRandom(); // return 2
//solution.getRandom(); // return 2
//solution.getRandom(); // return 3
//// getRandom() should return either 1, 2, or 3 randomly. Each element should 
//have equal probability of returning.
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in the linked list will be in the range [1, 10⁴]. 
// -10⁴ <= Node.val <= 10⁴ 
// At most 10⁴ calls will be made to getRandom. 
// 
//
// 
// Follow up: 
//
// 
// What if the linked list is extremely large and its length is unknown to you? 
//
// Could you solve this efficiently without using extra space? 
// 
// Related Topics Linked List Math Reservoir Sampling Randomized 👍 1036 👎 262


//leetcode submit region begin(Prohibit modification and deletion)
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

    private ListNode head;
    private Random random;

    public Solution(ListNode head) {
        this.head = head;
        this.random = new Random();
    }

    public int getRandom() {
        int len = 1;
        ListNode cur = head;
        ListNode res = null;
        while (cur != null) {
            int randomVal = random.nextInt(len);
            if (randomVal < 1) {
                res = cur;
            }
            cur = cur.next;
            ++len;
        }
        return res.val;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
//leetcode submit region end(Prohibit modification and deletion)
