/*
 * @lc app=leetcode id=779 lang=cpp
 *
 * [779] K-th Symbol in Grammar
 */
//ref: https://leetcode.com/problems/k-th-symbol-in-grammar/discuss/113705/JAVA-one-line
//ref: https://leetcode.com/problems/k-th-symbol-in-grammar/discuss/113705/JAVA-one-line
//     (comment below)
class SolutionA
{
    // Write down numbers of each row, all rows can be taken as different layers of a full binary tree
    // whose left subtree and right subtree are mirror images of each other, that is, they are symmetric.
    // Then for the first half numbers of the k-th row, the target number is the same as the number of the k-th number at the (N-1)-th row
    // For the right half numbers of the k-th row, the target number is the same as the opposite of  the k-th number at the (N-1)-th row

    // Or you can observe that the left part of k-th row is the same as the (k-1)-th row while the right part is its mirror image.
public:
    int kthGrammar(int N, int K)
    {
        if (N == 1 && K == 1)
            return 0;
        if (K <= (1 << (N - 2)))
            return kthGrammar(N - 1, K);
        else
            return kthGrammar(N - 1, K - (1 << N - 2)) ? 0 : 1;
    }
};

//ref: https://leetcode.com/problems/k-th-symbol-in-grammar/discuss/113697/My-3-lines-C%2B%2B-recursive-solution
class SolutionB
{
public:
    int kthGrammar(int N, int K)
    {
        if (N == 1)
            return 0;
        if (K % 2 == 0)
            return (kthGrammar(N - 1, K / 2) == 0) ? 1 : 0; // left child
        else
            return (kthGrammar(N - 1, (K + 1) / 2) == 0) ? 0 : 1; // right child
    }
};

//ref: https://leetcode.com/problems/k-th-symbol-in-grammar/discuss/113736/PythonJavaC%2B%2B-Easy-1-line-Solution-with-detailed-explanation
class Solution
{
public:
    int kthGrammar(int N, int K)
    {
        int cnt = 0;
        for (K -= 1; K >= 1;)
        {
            cnt += (K & 1);
            K >>= 1;
        }
        return cnt & 1;
    }
};
