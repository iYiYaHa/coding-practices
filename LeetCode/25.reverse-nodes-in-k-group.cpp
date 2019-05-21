/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
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
    // Seperate head-insertion method.
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode dummy(0);
        dummy.next = head;
        int count = 0;
        ListNode *prev = &dummy, *end = head;
        while (end != nullptr)
        {
            ++count;
            end = end->next;
            if (count == k)
            {
                ListNode *tmpHead = prev->next;
                ListNode *tmpEnd = tmpHead;
                ListNode *nextNode = tmpHead->next;
                tmpHead->next = end;
                while (nextNode != end)
                {
                    ListNode *tmp = nextNode->next;
                    nextNode->next = tmpHead;
                    tmpHead = nextNode;
                    nextNode = tmp;
                }
                prev->next = tmpHead;
                prev = tmpEnd;
                count = 0;
            }
        }
        return dummy.next;
    }
};

class Solution
{
    // Recursive method;
    ListNode *helper(ListNode *head, int k)
    {
        ListNode *end = head;
        int count = k;
        for (; end != nullptr && count != 0; end = end->next, --count);
        if (count == 0)
        {
            ListNode *nextNode = head->next;
            head->next = helper(end,k);
            while (nextNode != end)
            {
                ListNode *tmp = nextNode->next;
                nextNode->next = head;
                head = nextNode;
                nextNode = tmp;
            }
        }
        return head;
    }

public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        return helper(head, k);
    }
};
