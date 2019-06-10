/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// ref:https://leetcode.com/problems/intersection-of-two-linked-lists/discuss/49899/C%2B%2B-solution-using-XOR-trick
// ref:https://leetcode.com/problems/intersection-of-two-linked-lists/discuss/50020/Stupid-and-short-c%2B%2B-solution-without-any-list-cycles-O(N)-time-O(1)-memory
// ref:https://leetcode.com/problems/intersection-of-two-linked-lists/discuss/49925/Java-O(n)-time-O(1)-space-solution-by-using-%22assume-there-are-no-cycles%22
class SolutionA
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *ans = nullptr;
        stack<ListNode *> stackA;
        stack<ListNode *> stackB;
        for (ListNode *beg = headA; beg != nullptr; beg = beg->next)
            stackA.push(beg);
        for (ListNode *beg = headB; beg != nullptr; beg = beg->next)
            stackB.push(beg);
        while (!stackA.empty() && !stackB.empty())
        {
            ListNode *topA = stackA.top(), *topB = stackB.top();
            stackA.pop();
            stackB.pop();
            if (topA == topB)
                ans = topA;
            else
                break;
        }
        return ans;
    }
};

class SolutionB
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        // Count the length of two list.
        int lenA = 0, lenB = 0;
        for (ListNode *cur = headA; cur != nullptr; cur = cur->next)
            ++lenA;
        for (ListNode *cur = headB; cur != nullptr; cur = cur->next)
            ++lenB;

        // Cut off the longer part.
        ListNode *curA = headA, *curB = headB;
        int diff = lenA - lenB;
        for (; lenA > lenB; curA = curA->next, --lenA)
            ;
        for (; lenA < lenB; curB = curB->next, --lenB)
            ;

        // Find the intersection point.
        for (; curA != nullptr && curB != nullptr && curA != curB;)
        {
            curA = curA->next;
            curB = curB->next;
        }
        return curA;
    }
};

class SolutionC
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        set<ListNode *> visited;
        for (ListNode *cur = headA; cur != nullptr; cur = cur->next)
            visited.insert(cur);
        for (ListNode *cur = headB; cur != nullptr; cur = cur->next)
        {
            if (visited.count(cur))
                return cur;
        }
        return nullptr;
    }
};

class SolutionD
{
    // ref: https://leetcode.com/problems/intersection-of-two-linked-lists/solution/
    // ref: https://leetcode.com/problems/intersection-of-two-linked-lists/discuss/49785/Java-solution-without-knowing-the-difference-in-len!
    // "Actually we don't care about the "value" of difference, we just want to make sure two pointers reach the intersection node at the same time."
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (headA == nullptr || headB == nullptr)
            return nullptr;
        ListNode *ptrA = headA, *ptrB = headB;
        while (ptrA != ptrB)
        {
            ptrA = ptrA == nullptr ? headB : ptrA->next;
            ptrB = ptrB == nullptr ? headA : ptrB->next;
        }
        return ptrA;
    }
};
