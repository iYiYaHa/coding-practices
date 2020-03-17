#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    Solution() : ind(0), table(vector<int>(256, -1)) {}

    //Insert one char from stringstream
    void Insert(char ch)
    {
        ++ind;
        if (table[ch] == -1)
            table[ch] = ind;
        else
            table[ch] = -2;
    }
    //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        int minIndex = ind + 1;
        char minChar;
        for (int i = 0; i < 256; ++i)
        {
            if (table[i] > 0 && table[i]<minIndex)
            {
                minIndex = table[i];
                minChar = i;
            }
        }
        return minIndex == ind + 1 ? '#' : minChar;
    }

private:
    int ind;
    vector<int> table;
};

int main()
{
    Solution s;
    s.Insert('g');
    assert(s.FirstAppearingOnce() == 'g');
    s.Insert('o');
    assert(s.FirstAppearingOnce() == 'g');
    s.Insert('g');
    assert(s.FirstAppearingOnce() == 'o');
    s.Insert('o');
    s.Insert('l');
    s.Insert('e');
    assert(s.FirstAppearingOnce() == 'l');
    return 0;
}