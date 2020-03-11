#include<iostream>
#include<vector>

using namespace std;

struct ListNode{
    int val;
    struct ListNode* next;
    ListNode(int val_):val(val_),next(nullptr){}
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

class SolutionA {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(pHead == nullptr||pHead->next==nullptr) return pHead;

        ListNode fakeHead(0);
        fakeHead.next = pHead;

        ListNode *pre = &fakeHead;
        while(pre != nullptr){
            ListNode *beg = pre->next;
            ListNode *end = beg;
            while(end!=nullptr&&end->val==beg->val){
                end=end->next;
            }
            if(beg == end || beg->next==end){
                pre=pre->next;
            }else{
                pre->next = end;
                while(beg!=end){
                    ListNode *tmp = beg;
                    beg = beg->next;
                    delete tmp;
                }
            }
        }
        return fakeHead.next;
    }
};

class SolutionB {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(pHead == nullptr||pHead->next==nullptr) return pHead;
        ListNode *cur = pHead;
        while(cur != nullptr && cur->next != nullptr && cur->val == cur->next->val) cur = cur->next;
        if(cur == pHead){
            pHead->next = deleteDuplication(cur->next);
            return pHead;
        }
        else{
            return deleteDuplication(cur->next);
        }
    }
};

int main(){
    SolutionB s;
    vector<int> nums = {1,2,3,3,3,4,5,6,7,7,7,8,9,10,10,10,11,11};
    ListNode *pHead = nullptr, *pTail=nullptr;
    for(int num:nums){
        ListNode *newNode = new ListNode(num);
        if(pHead==nullptr){
            pHead=newNode;
            pTail=pHead;
        }
        else{
            pTail->next=newNode;
            pTail = newNode;
        }
    }
    printList(pHead);

    ListNode *res = s.deleteDuplication(pHead);

    printList(res);
    return 0;
}