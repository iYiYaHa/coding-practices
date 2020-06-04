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

class Solution
{
public:
    ListNode *FindKthToTail(ListNode *pListHead, unsigned int k)
    {
        if (pListHead == nullptr || k == 0)
            return nullptr;

        ListNode *pBeg = pListHead, *pEnd = pListHead;
        for (--k; k > 0; --k)
        {
            if(pEnd->next == nullptr){
                return nullptr;
            }else{
                pEnd = pEnd->next;
            }
        }

        while(pEnd->next != nullptr){
            pBeg = pBeg->next;
            pEnd = pEnd->next;
        }

        return pBeg;
    }
};

int main()
{

    Solution s;
    vector<int> nums = {1,2,3,4,5,6,7,8,9,10};
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

    ListNode *res = s.FindKthToTail(pHead, 10);

    printList(res);
    return 0;
}