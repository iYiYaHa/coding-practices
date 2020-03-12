#include <iostream>
#include <cmath>

using namespace std;

class Solution
{
public:
    int getDigitAtIndex(int index)
    {
        if (index < 0)
            return -1;
        int digits = 1;
        while (true)
        {
            int digitsOfRange = getDigitsOfRange(digits);
            if (index < digitsOfRange)
            {
                int target = getTargetNum(index, digits);
                int offsetDigitsFromRight = digits - index % digits;
                for (int i = offsetDigitsFromRight; i > 1; --i)
                {
                    target /= 10;
                }
                return target % 10;
            }
            index -= digitsOfRange;
            digits += 1;
        }
    }

private:
    int getDigitsOfRange(int digits)
    {
        if (digits <= 0)
            return 0;
        else if (digits == 1)
            return 10 * digits;
        else
            return 9 * pow(10, digits - 1) * digits;
    }

    int getTargetNum(int index, int digits)
    {
        int begNum = digits == 1 ? 0 : pow(10, digits - 1);
        int offsetNum = index / digits;
        return begNum + offsetNum;
    }
};

int main()
{
    Solution s;
    assert(s.getDigitAtIndex(5) == 5);
    assert(s.getDigitAtIndex(13) == 1);
    assert(s.getDigitAtIndex(19) == 4);
    assert(s.getDigitAtIndex(191) == 0);
    assert(s.getDigitAtIndex(181) == 5);
    return 0;
}