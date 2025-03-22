/*
 * @lc app=leetcode id=203 lang=cpp
 *
 * [203] Remove Linked List Elements
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
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *prev = &dummy;
        while (prev && prev->next)
        {
            if (prev->next->val == val)
            {
                ListNode *ele = prev->next;
                prev->next = prev->next->next;
                delete ele;
            }
            else
            {
                prev = prev->next;
            }
        }
        return dummy.next;
    }
};

class SolutionB
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        if (head == nullptr)
            return nullptr;
        if (head->val == val)
        {
            return removeElements(head->next, val);
        }
        else
        {
            head->next = removeElements(head->next, val);
            return head;
        }
    }
};
