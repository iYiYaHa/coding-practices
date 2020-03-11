#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class SolutionA
{
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
    {
        if (k <= 0 || k > input.size())
            return vector<int>();
        priority_queue<int> q;
        vector<int> ans;
        for (int num : input)
        {
            if (q.size() < k)
                q.push(num);
            else
            {
                int top = q.top();
                if (top > num)
                {
                    q.pop();
                    q.push(num);
                }
            }
        }
        while (!q.empty())
        {
            ans.push_back(q.top());
            q.pop();
        }
        return ans;
    }
};

class Solution
{
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
    {
        if (k <= 0 || k > input.size())
            return vector<int>();
        int left = 0, right = input.size() - 1;
        int index = -1;
        vector<int> ans;
        while (index != (k - 1))
        {
            index = partition(input, left, right);
            if (index < (k - 1))
            {
                left = index + 1;
            }
            else
            {
                right = index - 1;
            }
        }
        for (int i = 0; i < k; ++i)
        {
            ans.push_back(input[i]);
        }
        return ans;
    }

private:
    int partition(vector<int> &nums, int left, int right)
    {
        int tmp = left;
        left+=1;
        while (left <= right)
        {
            while (left <= right && nums[left] <= nums[tmp])
                ++left;
            while (left <= right && nums[right] >= nums[tmp])
                --right;
            
            if (left <= right)
            {
                swap(nums[left], nums[right]);
            }
        }
        swap(nums[tmp],nums[left-1]);
        return left - 1;
    }
};

bool isVectorEquals(const vector<int> &a, const vector<int> &b)
{
    if (a.size() != b.size())
        return false;
    vector<int> tmpA = a, tmpB = b;
    sort(tmpA.begin(), tmpA.end());
    sort(tmpB.begin(), tmpB.end());
    for (int i = 0; i < tmpA.size(); ++i)
    {
        if (tmpA[i] != tmpB[i])
            return false;
    }
    return true;
}
int main()
{
    Solution s;
    assert(isVectorEquals(s.GetLeastNumbers_Solution({1, 2, 3}, 3), {2, 3, 1}));
    assert(isVectorEquals(s.GetLeastNumbers_Solution({6, 5, 4, 3, 2, 1}, 4), {1, 2, 3, 4}));
    assert(isVectorEquals(s.GetLeastNumbers_Solution({3, 8, 29, 1, 10, -2, 34, -2, 1, 4, 4, -3, 0, -2, -5, -7}, 3), {-5, -3, -7}));
    assert(isVectorEquals(s.GetLeastNumbers_Solution({4, 5, 1, 6, 2, 7, 3, 8}, 4), {1, 2, 3, 4}));
}