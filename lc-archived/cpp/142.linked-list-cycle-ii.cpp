/*
 * @lc app=leetcode id=142 lang=cpp
 *
 * [142] Linked List Cycle II
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class SolutionA
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        set<ListNode *> visited;
        while (head != nullptr)
        {
            if (visited.count(head) != 0)
                return head;
            visited.insert(head);
            head = head->next;
        }
        return nullptr;
    }
};
class SolutionB
{
    // 如果有环，设环之前的长度为 2n，环的长度为 k。
    // 则慢指针（S)到达环的起点时，快指针（F）在离环起点距离 (2n)%k 处。
    // 设 S 和 F 相遇的位置在离环起点距离 c 处，则 c=(a_S*k+c)%k=(2n%k+2*a_S*k+2c)%k=(2n+2*a_S*k+2c)%k
    // (a_S*k+c) 为 S 在二者相遇时在环上走过的距离，(2n+2*a_S*k+2c) 为 F 在二者相遇时在环上走过的距离
    // 则由以上等式可知 2n + c = x*k x 为一个正整数
    // 由此可想到，如果让一个新的指针从 head 开始走 2n 的距离，恰好可以与 slow 指针在环的起点相遇。
    //
    // 如果不是看了答案有些思路，这个过程还是不太好推的。看下面第一个 ref！！！
    //
    // ref:http://fisherlei.blogspot.com/2013/11/leetcode-linked-list-cycle-ii-solution.html
    // ref:https://leetcode.com/problems/linked-list-cycle-ii/discuss/44781/Concise-O(n)-solution-by-using-C%2B%2B-with-Detailed-Alogrithm-Description
    // ref:https://leetcode.com/problems/linked-list-cycle-ii/discuss/44793/O(n)-solution-by-using-two-pointers-without-change-anything
    // ref:https://leetcode.com/problems/linked-list-cycle-ii/discuss/44915/Java-two-pointers-solution
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *fast = head, *slow = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast)
            { //circle
                ListNode *start = head;
                while (head != slow)
                {
                    head = head->next;
                    slow = slow->next;
                }
                return head;
            }
        }
        return nullptr;
    }
};
