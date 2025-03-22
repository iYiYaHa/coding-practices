#include <iostream>
#include <queue>
#include <exception>
#include <vector>

using namespace std;

class Solution
{
public:
    void Insert(int num)
    {
        int leftSize = left.size();
        int rightSize = right.size();
        if ((leftSize + rightSize) & 1)
        {
            if (!left.empty() && left.top() > num) // To maintain that the numbers of the right heap is larger than the left heap.
            {
                int topVal = left.top();
                left.pop();
                left.push(num);
                num = topVal;
            }
            right.push(num);
        }
        else
        {
            if (!right.empty() && right.top() < num) // To maintain that the numbers of the right heap is larger than the left heap.
            {
                int topVal = right.top();
                right.pop();
                right.push(num);
                num=topVal;
            }
            left.push(num);
        }
    }

    double GetMedian()
    {
        int leftSize = left.size();
        int rightSize = right.size();

        if (leftSize + rightSize == 0)
            throw runtime_error("No median for an empty stream.");
        else if ((leftSize + rightSize) & 1)
            return left.top();
        else
            return (left.top() + right.top())*1.0 / 2;
    }

private:
    priority_queue<int, vector<int>, std::less<int>> left;
    priority_queue<int, vector<int>, std::greater<int>> right;
};

int main()
{
    Solution s;
    s.Insert(1);
    assert(s.GetMedian() == 1);
    s.Insert(2);
    assert(s.GetMedian() == 1.5);
    s.Insert(3);
    assert(s.GetMedian() == 2);
    s.Insert(4);
    assert(s.GetMedian() == 2.5);
    s.Insert(5);
    assert(s.GetMedian() == 3);
    s.Insert(7);
    assert(s.GetMedian() == 3.5);
    s.Insert(3);
    assert(s.GetMedian() == 3);
    return 0;
}