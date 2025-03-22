class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int cnt = 0;
        while (n != 0)
        {
            cnt += 1;
            n = (n - 1) & n;
        }
        return cnt;
    }
};

class SolutionB
{
public:
    int hammingWeight(uint32_t n)
    {
        int cnt = 0;
        for (int i = 0; i < 32; ++i)
        {
            cnt += (n & (1 << i)) != 0 ? 1 : 0;
        }
        return cnt;
    }
};