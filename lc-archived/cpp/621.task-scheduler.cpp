/*
 * @lc app=leetcode id=621 lang=cpp
 *
 * [621] Task Scheduler
 *
 * https://leetcode.com/problems/task-scheduler/description/
 *
 * algorithms
 * Medium (47.58%)
 * Likes:    2476
 * Dislikes: 511
 * Total Accepted:    135.7K
 * Total Submissions: 285.2K
 * Testcase Example:  '["A","A","A","B","B","B"]\n2'
 *
 * Given a char array representing tasks CPU need to do. It contains capital
 * letters A to Z where different letters represent different tasks. Tasks
 * could be done without original order. Each task could be done in one
 * interval. For each interval, CPU could finish one task or just be idle.
 * 
 * However, there is a non-negative cooling interval n that means between two
 * same tasks, there must be at least n intervals that CPU are doing different
 * tasks or just be idle.
 * 
 * You need to return the least number of intervals the CPU will take to finish
 * all the given tasks.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: tasks = ["A","A","A","B","B","B"], n = 2
 * Output: 8
 * Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The number of tasks is in the range [1, 10000].
 * The integer n is in the range [0, 100].
 * 
 * 
 */

// ref:https://leetcode.com/problems/task-scheduler/solution/

// @lc code=start
class SolutionA
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        int cnt[26] = {};
        for (char ch : tasks)
        {
            cnt[ch - 'A']++;
        }
        int maxCnt = 0;
        int res = 0;
        for (int i = 0; i < 26; ++i)
        {
            maxCnt = max(maxCnt, cnt[i]);
        }
        res = (maxCnt - 1) * (n + 1);
        for (int i = 0; i < 26; ++i)
        {
            if (maxCnt == cnt[i])
                res++;
        }
        // 如果利用了所有的 idle slot, 都还有没有安排的任务，
        // 说明根本不需要 cooling time 就可以填满所有的 slot。
        return max(res, (int)tasks.size());
    }
};

// Inspired from solution 3 in the above reference.
class SolutionB
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        vector<int> cnt(26, 0);
        for (char ch : tasks)
        {
            cnt[ch - 'A']++;
        }
        int maxCnt = *max_element(cnt.begin(), cnt.end());

        int idleSlots = (maxCnt - 1) * (n + 1);
        for (int i = 0; i < 26; ++i)
        {
            idleSlots -= min(cnt[i], maxCnt - 1);
        }
        // 如果利用了所有的 idle slot, 都还有没有安排的任务，
        // 说明根本不需要 cooling time 就可以填满所有的 slot。
        return idleSlots > 0 ? idleSlots + tasks.size() : tasks.size();
    }
};

class SolutionC
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        vector<int> cnt(26, 0);
        for (char ch : tasks)
        {
            cnt[ch - 'A']++;
        }
        sort(cnt.begin(), cnt.end());
        int time = 0;
        while (cnt[25] > 0)
        {
            int i = 0;
            while (i <= n)
            {
                if (cnt[25] == 0)
                    break;
                if (i < 26 && cnt[25 - i] > 0)
                    --cnt[25 - i];
                ++i;
                ++time;
            }
            sort(cnt.begin(), cnt.end());
        }
        return time;
    }
};

//ref:https://leetcode.com/problems/task-scheduler/discuss/104493/C%2B%2B-Java-Clean-Code-Priority-Queue
class SolutionD
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        vector<int> cnt(26, 0);
        for (char ch : tasks)
        {
            cnt[ch - 'A']++;
        }
        priority_queue<int, std::vector<int>, std::less<int>> q;
        for (int num : cnt)
        {
            if (num != 0){
                q.push(num);
            }
        }
        int res = 0;
        while (!q.empty())
        {
            vector<int> tmp;
            int cntTask = 0;
            for (int i = 0; i < n + 1; ++i)
            {
                if (!q.empty())
                {
                    int times = q.top();
                    q.pop();
                    ++cntTask;
                    if (--times > 0){
                        tmp.push_back(times);
                    }
                }
            }
            for (int i : tmp)
            {
                q.push(i);
            }

            res += q.empty()?cntTask:n+1;
        }
        return res;
    }
};
// @lc code=end
