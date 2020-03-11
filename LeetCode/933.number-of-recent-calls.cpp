/*
 * @lc app=leetcode id=933 lang=cpp
 *
 * [933] Number of Recent Calls
 */

// @lc code=start
class RecentCounter
{
    queue<int> window;

public:
    RecentCounter()
    {
    }

    // int ping(int t)
    // {
    //     while (!window.empty() && t - window.front() > 3000)
    //         window.pop();
    //     window.push(t);
    //     return window.size();
    // }

        int ping(int t)
    {
        window.push(t);
        while (t - window.front() > 3000)
            window.pop();
        return window.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
// @lc code=end
