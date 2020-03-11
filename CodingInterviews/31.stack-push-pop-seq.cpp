#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV)
    {
        if (pushV.size() != popV.size())
            return false;
        stack<int> s;
        for (int i = 0, j = 0; j < popV.size(); ++j)
        {
            if (!s.empty() && s.top() == popV[j])// If the top element matches, pop it.
            {
                s.pop();
            }
            else// else 
            {
                while (i < pushV.size() && pushV[i] != popV[j])// Push the pushV sequence elements into the stack until we have found popV[j]
                {
                    s.push(pushV[i++]);
                }
                if (i == pushV.size())// If popV[j] not found in pushV
                {
                    return false;
                }else{// pushV[i] matches, then increment i.
                    ++i;
                }
            }
        }
        return true;
    }
};

void printRes(Solution &s, const vector<int> &A, const vector<int> &B)
{
    cout << "Push sequence: ";
    for (int num : A)
        cout << num << " ";
    cout << "Pop sequence: ";
    for (int num : B)
        cout << num << " ";
    if (s.IsPopOrder(A, B))
    {
        cout << "is correct.\n";
    }
    else
    {
        cout << "is wrong.\n";
    }
}
int main()
{
    Solution s;
    vector<int> pushSeq = {1, 2, 3, 4, 5};
    vector<int> popSeqA = {4, 5, 3, 2, 1};
    vector<int> popSeqB = {4, 3, 5, 1, 2};
    vector<int> popSeqC = {3, 2, 1};
    vector<int> popSeqD = {5, 4, 3, 2, 1};
    vector<int> popSeqE = {3, 5, 4, 1, 2};
    printRes(s, pushSeq, popSeqA);
    printRes(s, pushSeq, popSeqB);
    printRes(s, pushSeq, popSeqC);
    printRes(s, pushSeq, popSeqD);
    printRes(s, pushSeq, popSeqE);
    return 0;
}