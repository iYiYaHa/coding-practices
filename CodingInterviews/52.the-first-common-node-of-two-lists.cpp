#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int val_) : val(val_), next(nullptr) {}
};

class Solution
{
public:
    ListNode *FindFirstCommonNode(ListNode *pHeadA, ListNode *pHeadB)
    {
        int lenA = getListLength(pHeadA);
        int lenB = getListLength(pHeadB);

        if (lenA > lenB)
            pHeadA = walkForward(pHeadA,lenA-lenB);
        else
            pHeadB = walkForward(pHeadB,lenB-lenA);
        while (pHeadA!= nullptr && pHeadB != nullptr)
        {
            if(pHeadA == pHeadB)return pHeadA;
            pHeadA = pHeadA->next;
            pHeadB = pHeadB->next;
        }
        return nullptr;
    }
private:
    int getListLength(ListNode *pHead){
        int len = 0;
        while(pHead!=nullptr){
            pHead=pHead->next;
            ++len;
        }
        return len;
    }

    ListNode *walkForward(ListNode *pHead, int step){
        for(int i = 0;i<step;++i){
            pHead = pHead->next;
        }
        return pHead;
    }
};
