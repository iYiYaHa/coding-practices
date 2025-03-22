#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool VerifySquenceOfBST(vector<int> sequence)
    {
        if(sequence.size() == 0) return false; // Empty Sequence here!!!
        return helper(sequence, 0, sequence.size() - 1);
    }

private:
    bool helper(const vector<int> &seq, int beg, int end)
    {
        if (beg >= end) // Empty Tree!
            return true;

        int i = beg;
        for (; i < end && seq[i] <= seq[end]; ++i)
            ;

        int j = i;
        for (; j < end && seq[j] >= seq[end]; ++j)
            ;

        // j == end ensures that there is no node with values smaller than root value.
        return j == end && helper(seq, beg, i - 1)  // left subtree
                        && helper(seq, i, end - 1); // right subtree
    }
    
};

int main()
{
    Solution s;
    // vector<int> seq = {6};
    vector<int> seq = {6, 7};
    // vector<int> seq = {4,6,7,5};
    // vector<int> seq = {5, 7, 6, 9, 11, 10, 8};
    if (s.VerifySquenceOfBST(seq) == true)
        cout << "Yes!\n";
    else
        cout << "No!\n";
    return 0;
}