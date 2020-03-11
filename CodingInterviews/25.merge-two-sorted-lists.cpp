#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int val_) : val(val_), next(nullptr) {}
};

ListNode *constructList(const vector<int> &nums)
{
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
    return pHead;
}

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

class SolutionA {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1 == nullptr) return pHead2;
        if(pHead2 == nullptr) return pHead1;
        
        if(pHead1->val<=pHead2->val){
            pHead1->next = Merge(pHead1->next, pHead2);
            return pHead1;
        }
        else{
            pHead2->next = Merge(pHead1, pHead2->next);
            return pHead2;
        }
    }
};

class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        ListNode dummy(0), *end = &dummy;
        while(pHead1 != nullptr && pHead2 !=nullptr){
            if(pHead1->val <= pHead2->val){
                end->next = pHead1;
                pHead1 = pHead1->next;
            }else{
                end->next = pHead2;
                pHead2 = pHead2->next;
            }
            end = end->next;
        }
        pHead1 = pHead1 == nullptr? pHead2:pHead1;
        end->next = pHead1;
        return dummy.next;
    }
};

int main()
{
    Solution s;
    vector<int> numsA = {1,3,5,7,9};
    vector<int> numsB = {2,4,6,8,10};
    ListNode *pHeadA = constructList(numsA);
    ListNode *pHeadB = constructList(numsB);
    printList(pHeadA);
    printList(pHeadB);
    ListNode *res = s.Merge(pHeadA,pHeadB);

    printList(res);
    return 0;
}