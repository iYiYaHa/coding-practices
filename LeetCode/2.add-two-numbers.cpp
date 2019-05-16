/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
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
    // One-time-pass, I'm so niubi.
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *head = new ListNode(0);
        ListNode *end = head;
        int carry = 0;
        while (l1 != nullptr && l2 != nullptr)
        {
            int sum = l1->val + l2->val + carry;
            int val = sum % 10;
            carry = sum / 10;
            l1->val = val;
            end->next = l1;
            end = end->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        l1 = l1 == nullptr ? l2 : l1;
        while (l1 != nullptr)
        {
            int sum = l1->val + carry;
            int val = sum % 10;
            carry = sum / 10;
            l1->val = val;
            end->next = l1;
            end = end->next;
            l1 = l1->next;
        }
        if (carry != 0)
        {
            ListNode *lastNode = new ListNode(carry);
            end->next = lastNode;
            end = end->next;
        }
        return head->next;
    }
};
class SolutionB
{
private:
    ListNode *helper(ListNode *l1, ListNode *l2, int carry)
    {
        if (l1 == nullptr && l2 == nullptr)
        {
            return carry == 0 ? nullptr : new ListNode(carry);
        }
        else if (l1 == nullptr && l2 != nullptr)
        {
            int sum = l2->val + carry;
            int val = sum % 10;
            carry = sum / 10;
            l2->val = val;
            l2->next = helper(nullptr, l2->next, carry);
            return l2;
        }
        else if (l1 != nullptr && l2 == nullptr)
        {
            int sum = l1->val + carry;
            int val = sum % 10;
            carry = sum / 10;
            l1->val = val;
            l1->next = helper(nullptr, l1->next, carry);
            return l1;
        }
        else
        {
            int sum = l1->val + l2->val + carry;
            int val = sum % 10;
            carry = sum / 10;
            l1->val = val;
            l1->next = helper(l1->next, l2->next, carry);
            return l1;
        }
    }

public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        return helper(l1, l2, 0);
    }
};
class Solution
{
private:
    ListNode *helper(ListNode *l1, ListNode *l2, int carry)
    {
        if (l1 == nullptr && l2 == nullptr)
        {
            return carry == 0 ? nullptr : new ListNode(carry);
        }
        int a = l1 == nullptr ? 0 : l1->val;
        int b = l2 == nullptr ? 0 : l2->val;
        ListNode *currNode = l1 == nullptr ? l2 : l1;
        
        int sum = a + b + carry;
        int val = sum % 10;
        carry = sum / 10;
        currNode->val = val;

        ListNode *l1Next = l1 == nullptr ? nullptr : l1->next;
        ListNode *l2Next = l2 == nullptr ? nullptr : l2->next;
        currNode->next = helper(l1Next, l2Next, carry);
        return currNode;
    }

public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        return helper(l1, l2, 0);
    }
};
