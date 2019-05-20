/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
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
    ListNode *swapPairs(ListNode *head)
    {
        ListNode dummyNode(0);
        dummyNode.next = head;
        ListNode *prev = &dummyNode;
        while (prev->next != nullptr && prev->next->next != nullptr)
        {
            ListNode *former = prev->next;
            ListNode *latter = former->next;
            former->next = latter->next;
            latter->next = former;
            prev->next = latter;
            prev = former;
        }
        return dummyNode.next;
    }
};

class SolutionB
{
    // Recursive Solution
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *former = head;
        ListNode *latter = former->next;
        former->next = swapPairs(latter->next);
        latter->next=former;
        return latter;
    }
};
