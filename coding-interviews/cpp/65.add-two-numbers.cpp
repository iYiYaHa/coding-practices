#include <iostream>

class Solution
{
public:
    int Add(int num1, int num2)
    {
        int sum = 0;
        int carry = 0;
        do{
            sum = num1^num2;
            carry = (num1&num2)<<1;
            num1 = sum;
            num2 = carry;
        }while(carry != 0);
        return num1;
    }
};

int main()
{
    Solution s;
    assert(s.Add(3, 5) == 8);
    assert(s.Add(0, 5) == 5);
    assert(s.Add(5, 0) == 5);
    assert(s.Add(-3, 3) == 0);
    assert(s.Add(-3, 0) == -3);
    return 0;
}