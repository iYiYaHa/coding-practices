#include<iostream>
#include<string>
#include<numeric>

using namespace std;

class Solution
{
public:
    int StrToInt(string str)
    {
        if (str.size() < 0)
            return 0;
        bool isMinus = false;
        int ind = 0;
        long long num = 0;

        // Remove starting zeros
        while (ind < str.size() && str[ind] == ' ')
            ++ind;

        // Process the sign
        if (str[ind] == '-' || str[ind] == '+')
        {
            isMinus = str[ind] == '-';
            ++ind;
        }

        while (ind < str.size() && str[ind] <= '9' && str[ind] >= '0')
        {
            num = (num << 3) + (num << 1);
            num += str[ind] - '0';
            if ((isMinus && num > 0x80000000) || (!isMinus && num > 0x7FFFFFFF))
                break;
            ++ind;
        }
        if (ind != str.size())
        //throw invalid_argument();
            return 0;
        return isMinus ? -num : num;
    }
};

int main(){
    Solution s;
    cout<<std::numeric_limits<int>::min()<<" "<<std::numeric_limits<int>::max()<<endl;
    assert(s.StrToInt("0") == 0);
    assert(s.StrToInt("12345") == 12345);
    assert(s.StrToInt("123450") == 123450);
    assert(s.StrToInt("        1234") == 1234);
    assert(s.StrToInt("-1") == -1);
    assert(s.StrToInt("-2147483648") == -2147483648);
    assert(s.StrToInt("-2147483649") == 0);
    assert(s.StrToInt("2147483647") == 2147483647);
    assert(s.StrToInt("") == 0);
    
    return 0;
}

