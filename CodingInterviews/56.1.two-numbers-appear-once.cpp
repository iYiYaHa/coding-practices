class Solution
{
public:
    void FindNumsAppearOnce(vector<int> data, int *num1, int *num2)
    {
        *num1 = 0;
        *num2 = 0;
        int xorRes = 0;
        for (int num : data)
            xorRes ^= num;

        int pos = 0;
        while ((xorRes & (1 << pos)) == 0)
        {
            ++pos;
        }

        for (int num : data)
        {
            if (num & (1 << pos))
            {
                *num1 ^= num;
            }
            else
            {
                *num2 ^= num;
            }
        }
    }
};