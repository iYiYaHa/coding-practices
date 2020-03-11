/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
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
    // Use a window of length n to keep last accessed n elements.
    // Use a fake linked list head to simplify the logic. This is a really important trick.
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode fakeHead(0);
        fakeHead.next = head;
        ListNode *wFront = &fakeHead, *wRear = &fakeHead;
        int size = 0;
        while (wRear->next != nullptr)
        {
            if (size < n)
                ++size;
            else
                wFront = wFront->next;
            wRear = wRear->next;
        }
        if (size == n)
        {
            ListNode *tmp = wFront->next;
            wFront->next = tmp->next;
            delete tmp;
        }
        return fakeHead.next;
    }
};

class SolutionB
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode fakeHead(-1);
        fakeHead.next = head;
        int len = 0;
        // Count the length
        for (ListNode *cur = head; cur != nullptr; cur = cur->next, ++len)
            ;

        // Find the previous node
        ListNode *prev = &fakeHead;
        int cutPos = len - n;
        for (; cutPos > 0; --cutPos, prev = prev->next)
            ;

        ListNode *tmp = prev->next;
        prev->next = tmp->next;
        delete tmp;
        return fakeHead.next;
    }
};

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (head == nullptr || n <= 0)
            return head;
        ListNode fakeHead(0);
        fakeHead.next = head;

        ListNode *pBeg = &fakeHead, *pEnd = &fakeHead;
        for (int i = 0; i < n; ++i)
        {
            if (pEnd->next != nullptr)
            {
                pEnd = pEnd->next;
            }
            else
            {
                return fakeHead.next;
            }
        }
        while (pEnd->next != nullptr)
        {
            pBeg = pBeg->next;
            pEnd = pEnd->next;
        }
        ListNode *tmp = pBeg->next;
        pBeg->next = tmp->next;
        delete tmp;

        return fakeHead.next;
    }
};
