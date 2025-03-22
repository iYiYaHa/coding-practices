#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int val_) : val(val_), next(nullptr) {}
};

void printList(ListNode *pHead)
{
    if (pHead != nullptr)
    {
        cout << pHead->val;
        if (pHead->next)
            cout << "->";
        printList(pHead->next);
    }
    else
    {
        cout << endl;
    }
}

class SolutionA
{
public:
    ListNode *ReverseList(ListNode *pHead)
    {
        if (pHead == nullptr || pHead->next == nullptr)
            return pHead;
        ListNode *left = ReverseList(pHead->next);
        pHead->next->next = pHead;
        pHead->next = nullptr;
        return left;
    }
};

class SolutionB
{
public:
    ListNode *ReverseList(ListNode *pHead)
    {
        ListNode dummy(0);
        while (pHead != nullptr)
        {
            ListNode *first = pHead;
            pHead = pHead->next;
            first->next = dummy.next;
            dummy.next = first;
        }
        return dummy.next;
    }
};

class Solution
{
public:
    ListNode *ReverseList(ListNode *pHead)
    {
        ListNode *newHead = nullptr;
        while(pHead!=nullptr){
            ListNode *ele = pHead;
            pHead = pHead->next;
            ele->next = newHead;
            newHead = ele;
        }
        return newHead;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 2, 3, 3, 3, 4, 5, 6, 7, 7, 7, 8, 9, 10, 10, 10, 11, 11};
    ListNode *pHead = nullptr, *pTail = nullptr;
    for (int num : nums)
    {
        ListNode *newNode = new ListNode(num);
        if (pHead == nullptr)
        {
            pHead = newNode;
            pTail = pHead;
        }
        else
        {
            pTail->next = newNode;
            pTail = newNode;
        }
    }
    printList(pHead);

    ListNode *res = s.ReverseList(pHead);

    printList(res);
    return 0;
}