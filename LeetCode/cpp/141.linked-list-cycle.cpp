/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Another thought just for reference as it breaks the structure of the original linked list.
// Ref:https://leetcode.com/problems/linked-list-cycle/discuss/44603/Shorter-Solution-in-Java

class SolutionA
{
    // Slow-fast pointers
    // ref:https://leetcode.com/problems/linked-list-cycle/solution/
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *slow = head, *fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast)
                return true;
        }
        return false;
    }
};

class SolutionB
{
public:
    bool hasCycle(ListNode *head)
    {
        set<ListNode *> visited;
        ListNode *cur = head;
        while (cur != nullptr)
        {
            if (visited.count(cur) != 0)
                return true;
            visited.insert(cur);
            cur=cur->next;
        }
        return false;
    }
};
