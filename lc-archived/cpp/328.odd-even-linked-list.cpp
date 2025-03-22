/*
 * @lc app=leetcode id=328 lang=cpp
 *
 * [328] Odd Even Linked List
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
    // Remember to cut off the link between current element and the rest of the list
public:
    ListNode *oddEvenList(ListNode *head)
    {
        ListNode odd(0), even(0);
        ListNode *oddEnd = &odd, *evenEnd = &even;
        int i = 1;
        while (head != nullptr)
        {
            ListNode *ele = head;
            head = head->next;
            ele->next = nullptr;
            if (i & 1)
            {
                oddEnd->next = ele;
                oddEnd = ele;
                i = 0;
            }
            else
            {
                evenEnd->next = ele;
                evenEnd = ele;
                i = 1;
            }
        }
        oddEnd->next = even.next;
        return odd.next;
    }
};

class SolutionB
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;
        ListNode *oddEnd = head, *evenEnd = head->next;
        while (evenEnd && evenEnd->next)
        {
            ListNode *ele = evenEnd->next;

            // Skip even element.
            evenEnd->next = ele->next;
            evenEnd = ele->next;

            // Insert odd element behind the end of odd elements.
            ele->next = oddEnd->next;
            oddEnd->next = ele;
            oddEnd = ele;
        }
        return head;
    }
};

class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;
            
        ListNode *oddEnd = head, *evenEnd = head->next, *evenHead = head->next;
        while (evenEnd && evenEnd->next)
        {
            ListNode *ele = evenEnd->next;

            oddEnd->next = ele;
            oddEnd = oddEnd->next;
            evenEnd->next = ele->next;
            evenEnd = evenEnd->next;
        }
        oddEnd->next = evenHead;
        return head;
    }
};
