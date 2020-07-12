/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
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
    ListNode *rotateRight(ListNode *head, int k)
    {
        ListNode dummy(0);
        dummy.next = head;
        int len = 0;
        while (head != nullptr)
        {
            ++len;
            head = head->next;
        }
        if (len != 0)
            k %= len;

        ListNode *prev = &dummy, *end = &dummy;
        while (end->next != nullptr)
        {
            if (k != 0)
            {
                --k;
            }
            else
            {
                prev = prev->next;
            }
            end = end->next;
        }
        // Shift the part between prev->next and end before the front
        end->next = dummy.next;
        dummy.next = prev->next;
        prev->next = nullptr;
        return dummy.next;
    }
};

class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        int len = 1;
        ListNode *end = head;
        while (end->next != nullptr)
        {
            ++len;
            end = end->next;
        }
        end->next = head; // Make it a circle
        k %= len;

        // Break at len-k
        for (int i = 0; i < len - k; ++i)
        {
            end = end->next;
        }
        ListNode *res = end->next;
        end->next = nullptr;
        return res;
    }
};
