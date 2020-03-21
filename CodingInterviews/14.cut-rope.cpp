/*
    Problem: Cut Rope
    Type: Dynamic Programming or Greedy Algorithm.
    Note:
        Similar problems with integer break problem in leetcode.
*/
// Dynamic Programming
class Solution
{
    // This one looks better than othere implementations with a clean and tidy style.
public:
    int cutRope(int number)
    {
        if (number < 2 || number > 60)
            return 0;
        vector<int> dp(number + 1);
        for (int i = 1; i <= number; ++i)
        {
            for (int j = 1; j <= i / 2; ++j)
            {
                dp[i] = max(dp[i], j * max(i - j, dp[i - j])); // For each i-j, we can choose to break it or not.
            }
        }
        return dp[number];
    }
};

class SolutionB
{
public:
    int cutRope(int number)
    {
        if (number < 2)
            return 0;
        if (number == 2)
            return 1;
        else if (number == 3)
            return 2;

        vector<int> dp(4 + number, 0);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        for (int i = 4; i <= number; ++i)
        {
            for (int j = 1; j <= i / 2; ++j)
            {
                dp[i] = max(dp[i], dp[j] * dp[i - j]);
            }
        }
        return dp[number];
    }
};

class SolutionC
{
public:
    int cutRope(int number)
    {
        if (number < 2)
            return 0;
        vector<int> dp(number + 1);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= number; ++i)
        {
            if (i != number)
            {
                dp[i] = i;
            }
            else
            {
                dp[i] = 1;
            }
            for (int j = 1; j <= i / 2; ++j)
            {
                dp[i] = max(dp[i], dp[j] * dp[i - j]);
            }
        }
        return dp[number];
    }
};

// Greedy Algorithm.
class SolutionD
{
    // This solution is a greedy algorithm without solid proof found on the Internet.
public:
    int cutRope(int number)
    {
        if (number < 2)
            return 0;
        if (number == 2)
            return 1;
        else if (number == 3)
            return 2;
        int numberThree = number / 3;
        if (number - numberThree * 3 == 1)
            --numberThree;
        int numberTwo = (number - numberThree * 3) / 2;
        return pow(3, numberThree) * pow(2, numberTwo);
    }
};

class Solution
{
public:
    int cuttingRope(int n)
    {
        if (n <= 0)
            return 0;
        if (n == 1)
            return 1;
        if (n == 2)
            return 1;
        if (n == 3)
            return 2;
        int a = n / 3;
        int b = n % 3;
        if (b == 0)
            return pow(3, a);
        else if (b == 1)
            return pow(3, a - 1) * 4;
        else
            return pow(3, a) * 2;
    }
};