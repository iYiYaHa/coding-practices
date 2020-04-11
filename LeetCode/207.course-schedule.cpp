/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 *
 * https://leetcode.com/problems/course-schedule/description/
 *
 * algorithms
 * Medium (40.87%)
 * Likes:    3080
 * Dislikes: 157
 * Total Accepted:    343.1K
 * Total Submissions: 832.8K
 * Testcase Example:  '2\n[[1,0]]'
 *
 * There are a total of numCourses courses you have to take, labeled from 0 to
 * numCourses-1.
 * 
 * Some courses may have prerequisites, for example to take course 0 you have
 * to first take course 1, which is expressed as a pair: [0,1]
 * 
 * Given the total number of courses and a list of prerequisite pairs, is it
 * possible for you to finish all courses?
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: numCourses = 2, prerequisites = [[1,0]]
 * Output: true
 * Explanation: There are a total of 2 courses to take. 
 * To take course 1 you should have finished course 0. So it is possible.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
 * Output: false
 * Explanation: There are a total of 2 courses to take. 
 * To take course 1 you should have finished course 0, and to take course 0 you
 * should
 * also have finished course 1. So it is impossible.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The input prerequisites is a graph represented by a list of edges, not
 * adjacency matrices. Read more about how a graph is represented.
 * You may assume that there are no duplicate edges in the input
 * prerequisites.
 * 1 <= numCourses <= 10^5
 * 
 * 
 */

// @lc code=start
class SolutionA
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        queue<int> q;
        vector<int> degree(numCourses, 0);
        int visitedNodes = 0;
        vector<vector<int>> graph(numCourses);
        for (vector<int> &pair : prerequisites)
        {
            graph[pair[0]].push_back(pair[1]);
            ++degree[pair[1]];
        }
        for (int i = 0; i < degree.size(); ++i)
        {
            if (degree[i] == 0)
            {
                q.push(i);
            }
        }
        while (!q.empty())
        {
            int fromNode = q.front();
            q.pop();
            ++visitedNodes;
            for (int toNode : graph[fromNode])
            {
                --degree[toNode];
                if (degree[toNode] == 0)
                {
                    q.push(toNode);
                }
            }
        }
        return visitedNodes == numCourses;
    }
};

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> graph(numCourses);
        for (vector<int> &pair : prerequisites)
        {
            graph[pair[0]].push_back(pair[1]);
        }
        return !hasCircle(graph);
    }

private:
    bool hasCircle(const vector<vector<int>> &graph)
    {
        vector<int> visiting(graph.size(), 0);
        for (int i = 0; i < graph.size(); ++i)
        {
            if (visiting[i] == 0) // 未访问
            {
                if (hasCircleDfs(graph, visiting, i))
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool hasCircleDfs(const vector<vector<int>> &graph, vector<int> &visiting, int node)
    {
        if (visiting[node] == 1)
        {
            return true;
        }

        visiting[node] = 1; // 正在访问
        for (int toNode : graph[node])
        {
            if (hasCircleDfs(graph, visiting, toNode))
                return true;
        }
        visiting[node] = 2; // 访问过
        return false;
    }
};
// @lc code=end
