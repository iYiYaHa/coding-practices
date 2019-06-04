/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
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
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *left = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return left;
    }
};

class SolutionB
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode dummy(0);
        ListNode *cur = head;
        while (cur != nullptr)
        {
            ListNode *tmp = cur->next;
            cur->next = dummy.next;
            dummy.next = cur;
            cur = tmp;
        }
        return dummy.next;
    }
};

class SolutionC
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr)
            return head;
        ListNode *cur = head->next;
        head->next = nullptr;
        while (cur != nullptr)
        {
            ListNode *ele = cur;
            cur = cur->next;
            ele->next = head;
            head = ele;
        }
        return head;
    }
};
