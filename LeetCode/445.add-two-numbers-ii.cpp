/*
 * @lc app=leetcode id=445 lang=cpp
 *
 * [445] Add Two Numbers II
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
    // Using stack to reverse numbers.
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode dummy(0);

        stack<ListNode *> stackA, stackB;
        for (ListNode *cur = l1; cur != nullptr; cur = cur->next)
            stackA.push(cur);
        for (ListNode *cur = l2; cur != nullptr; cur = cur->next)
            stackB.push(cur);

        int carry = 0;
        while (!stackA.empty() && !stackB.empty())
        {
            ListNode *topA = stackA.top();
            stackA.pop();
            ListNode *topB = stackB.top();
            stackB.pop();

            int val = topA->val + topB->val + carry;
            carry = val / 10;
            val = val % 10;

            ListNode *newNode = new ListNode(val);
            newNode->next = dummy.next;
            dummy.next = newNode;
        }

        stack<ListNode *> &left = !stackA.empty() ? stackA : stackB;
        while (!left.empty())
        {
            ListNode *topEle = left.top();
            left.pop();
            int val = topEle->val + carry;
            carry = val / 10;
            val = val % 10;
            ListNode *newNode = new ListNode(val);
            newNode->next = dummy.next;
            dummy.next = newNode;
        }

        if (carry != 0)
        {
            ListNode *newNode = new ListNode(carry);
            newNode->next = dummy.next;
            dummy.next = newNode;
        }
        return dummy.next;
    }
};

class Solution
{
    // Using stack to reverse numbers.
    // With logic optimized.
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode dummy(0);

        stack<ListNode *> stackA, stackB;
        for (ListNode *cur = l1; cur != nullptr; cur = cur->next)
            stackA.push(cur);
        for (ListNode *cur = l2; cur != nullptr; cur = cur->next)
            stackB.push(cur);

        int carry = 0;
        while (!stackA.empty() || !stackB.empty() || carry != 0)
        {
            int val = carry;
            if (!stackA.empty())
            {
                ListNode *topA = stackA.top();
                stackA.pop();
                val += topA->val;
            }
            if (!stackB.empty())
            {
                ListNode *topB = stackB.top();
                stackB.pop();
                val += topB->val;
            }
            carry = val / 10;
            val = val % 10;
            ListNode *newNode = new ListNode(val);
            newNode->next = dummy.next;
            dummy.next = newNode;
        }
        return dummy.next;
    }
};
