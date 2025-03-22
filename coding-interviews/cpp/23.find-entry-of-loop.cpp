/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/

// See Leetcode 142
class Solution
{
public:
    ListNode *EntryNodeOfLoop(ListNode *pHead)
    {
        ListNode *slow = pHead, *fast = pHead;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                fast = pHead;
                while (slow != fast)
                {
                    slow = slow->next;
                    fast = fast->next;
                }
                return fast;
            }
        }
        return nullptr;
    }
};

class Solution
{
public:
    ListNode *EntryNodeOfLoop(ListNode *pHead)
    {
        ListNode *pMeet = findMeetingPoint(pHead);
        if (pMeet == nullptr)
            return nullptr;
        int len = 1;
        for (ListNode *cur = pMeet; *cur != pMeet; cur = cur->next)
            ++len;
        ListNode *slow = pHead, *fast = pHead;
        for (int i = 0; i < len; ++i)
            fast = fast->next;
        while(slow!=fast){
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
    }

private:
    ListNode *findMeetingPoint(ListNode *head)
    {
        ListNode *slow = head, *fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return slow;
        }
        return nullptr;
    }
};