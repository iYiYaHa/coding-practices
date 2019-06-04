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
        while (head != nullptr)
        {
            ListNode *ele = head;
            head = head->next;
            ele->next = dummy.next;
            dummy.next = ele;
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
