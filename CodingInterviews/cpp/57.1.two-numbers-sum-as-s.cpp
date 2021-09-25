#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    // If we have more than one pair whose sum satisifies the requirement and we need to output the pair with the smallest product.
    // x+y = s Let y>=x, y-x=d>=0
    // f(x,y) = x * y = (s^2-d^2)/4 = f(d)
    // As d>=0, the larger d is, the smaller the product is.
    // Then the pair with the outmost positions is the one with the smallest product.
public:
    vector<int> FindNumbersWithSum(vector<int> array, int sum)
    {
        int left = 0, right = array.size() - 1;
        while (left <= right)
        {
            int tmpSum = array[left] + array[right];
            if (tmpSum == sum)
                return vector<int>({array[left], array[right]});
            else if (tmpSum > sum)
            {
                --right;
            }
            else
                ++left;
        }
        return vector<int>({});
    }
};

int main()
{
    Solution s;
    assert(s.FindNumbersWithSum({1, 2, 3, 4, 7, 11, 12, 15}, 15) == vector<int>({4, 11}));
    return 0;
}