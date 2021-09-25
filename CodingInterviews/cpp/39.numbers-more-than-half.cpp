#include <iostream>
#include <vector>
#include<unordered_map>
using namespace std;

class SolutionA
{
public:
    int MoreThanHalfNum_Solution(vector<int> numbers)
    {
        if (numbers.size() <= 0)
            return 0;
        int target = 0;
        int cnt = 0;
        for (int i = 0; i < numbers.size(); ++i)
        {
            if (cnt == 0)
            {
                target = numbers[i];
                cnt = 1;
            }
            else
            {
                if (numbers[i] == target) ++cnt;
                else --cnt;
            }
        }
        int maxValCnt = 0;
        for(int num:numbers){if(num == target)++maxValCnt;}
        return maxValCnt>(numbers.size()>>1) ? target : 0;
    }
};

class Solution
{
public:
    int MoreThanHalfNum_Solution(vector<int> numbers)
    {
        if(numbers.size() == 0) return 0;
        int left = 0, right = numbers.size() - 1;
        int mid = numbers.size() >> 1;
        int index = -1;
        while (index != mid)
        {
            index = partition(numbers, left, right);
            if (index > mid)
            {
                right = index - 1;
            }
            else
            {
                left = index + 1;
            }
        }
        int target = numbers[index];
        int maxValCnt = 0;
        for(int num:numbers){if(num == target)++maxValCnt;}
        return maxValCnt>(numbers.size()>>1) ? target : 0;
    }

private:
    int partition(vector<int> &nums, int left, int right)
    {
        int tmp = nums[left];
        while (left <= right)
        {
            while (left <= right && nums[left] <= tmp)
                ++left;
            while (left <= right && nums[right] >= tmp)
                --right;
            if (left <= right)
            {
                swap(nums[left], nums[right]);
            }
        }
        return left-1;
    }
};

int main()
{
    Solution s;
    assert(s.MoreThanHalfNum_Solution({1, 1, 1, 1, 1, 2, 2, 2, 2}) == 1);
    cin.get();
    assert(s.MoreThanHalfNum_Solution({3, 3, 4, 3, 2, 5, 5, 5, 5, 5, 5, 5, 5, 5, 8, 2, 5, 3, 4, 3, 2, 3, 5, 5, 5}) == 5);
    assert(s.MoreThanHalfNum_Solution({1,2,3,2,4,2,5,2,3}) == 0);
    return 0;
}