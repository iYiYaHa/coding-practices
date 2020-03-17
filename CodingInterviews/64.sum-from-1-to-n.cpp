#include <iostream>

using namespace std;
// -------------------------------------------------------------------
class Helper
{
public:
    Helper()
    {
        N += 1;
        sum += N;
        cout << "N:" << N << " SUM:" << sum << endl;
    }
    static int getSum()
    {
        return sum;
    }
    static void reset()
    {
        sum = 0;
        N = 0;
    }

private:
    static int N;
    static int sum;
};

int Helper::N = 0;
int Helper::sum = 0;

class SolutionA
{
public:
    int Sum_Solution(int n)
    {
        Helper::reset();
        Helper helpers[n];
        return Helper::getSum();
    }
};

// -------------------------------------------------------------------
class A;
A *arr[2];

class A
{
public:
    virtual int sum(int n) { return 0; }
};

class B : public A
{
public:
    int sum(int n)
    {
        return arr[(n - 1) != 0]->sum(n - 1) + n;
    }
};

class SolutionB
{
public:
    int Sum_Solution(int n)
    {
        A *a = new A();
        B *b = new B();
        arr[0] = a;
        arr[1] = b;
        int res = b->sum(n);
        delete a;
        delete b;
        arr[0] = nullptr;
        arr[1] = nullptr;
        return res;
    }
};
// -------------------------------------------------------------------
int (*funcArray[2])(int);

int funcTerminal(int n)
{
    return 0;
}

int funcMiddle(int n)
{
    return funcArray[(n - 1) != 0](n - 1) + n;
}

class Solution
{
public:
    int Sum_Solution(int n)
    {
        funcArray[0] = funcTerminal;
        funcArray[1] = funcMiddle;
        return funcArray[1](n);
    }
};

// -------------------------------------------------------------------

template<unsigned int n> class SolutionD
{
    public:
    enum Value{N = SolutionD<n-1>::N+n};
};

template<> class SolutionD<1>{
    public:
    enum Value{N = 1};
};

int main()
{
    Solution s;
    assert(s.Sum_Solution(100) == (101 * 100 / 2));
    assert(s.Sum_Solution(100) == 101 * 100 / 2);
    assert(s.Sum_Solution(5) == 15);
    
    assert(SolutionD<100>::N == 5050);
    return 0;
}