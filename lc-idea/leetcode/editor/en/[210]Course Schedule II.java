//There are a total of numCourses courses you have to take, labeled from 0 to 
//numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai,
// bi] indicates that you must take course bi first if you want to take course ai.
// 
//
// 
// For example, the pair [0, 1], indicates that to take course 0 you have to 
//first take course 1. 
// 
//
// Return the ordering of courses you should take to finish all courses. If 
//there are many valid answers, return any of them. If it is impossible to finish all 
//courses, return an empty array. 
//
// 
// Example 1: 
//
// 
//Input: numCourses = 2, prerequisites = [[1,0]]
//Output: [0,1]
//Explanation: There are a total of 2 courses to take. To take course 1 you 
//should have finished course 0. So the correct course order is [0,1].
// 
//
// Example 2: 
//
// 
//Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
//Output: [0,2,1,3]
//Explanation: There are a total of 4 courses to take. To take course 3 you 
//should have finished both courses 1 and 2. Both courses 1 and 2 should be taken 
//after you finished course 0.
//So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3
//].
// 
//
// Example 3: 
//
// 
//Input: numCourses = 1, prerequisites = []
//Output: [0]
// 
//
// 
// Constraints: 
//
// 
// 1 <= numCourses <= 2000 
// 0 <= prerequisites.length <= numCourses * (numCourses - 1) 
// prerequisites[i].length == 2 
// 0 <= ai, bi < numCourses 
// ai != bi 
// All the pairs [ai, bi] are distinct. 
// 
// Related Topics Depth-First Search Breadth-First Search Graph Topological 
//Sort 👍 4984 👎 192


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        int[] ans = new int[numCourses];
        int ansInd = 0;
        // node -> degree
        int[] degree = new int[numCourses];
        // course -> its neighbors
        Map<Integer, List<Integer>> neighbors = new HashMap<>();

        // Process neighbors and degree of each course
        for (int[] prerequisite : prerequisites) {
            int to = prerequisite[0];
            int from = prerequisite[1];
            neighbors.computeIfAbsent(from, ArrayList<Integer>::new).add(to);
            ++degree[to];
        }

        // Initialize the courses with zero degree
        Queue<Integer> zeroDegreeCourses = new LinkedList<>();
        for (int i = 0; i < numCourses; ++i) {
            if (degree[i] == 0) {
                zeroDegreeCourses.add(i);
            }
        }

        // Topological sort
        int learnedCoursesCnt = 0;
        while (!zeroDegreeCourses.isEmpty()) {
            int course = zeroDegreeCourses.poll();
            ++learnedCoursesCnt;
            ans[ansInd++] = course;
            if (neighbors.containsKey(course)) {
                for (int neighbor : neighbors.get(course)) {
                    --degree[neighbor];
                    if (degree[neighbor] == 0) {
                        zeroDegreeCourses.add(neighbor);
                    }
                }
            }
        }
        return learnedCoursesCnt == numCourses ? ans : new int[]{};
    }
}

class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        int[] visited = new int[numCourses];
        List<Integer> path = new LinkedList<>();

        // course -> its neighbors
        Map<Integer, List<Integer>> graph = new HashMap<>();

        // Process neighbors and degree of each course
        for (int[] prerequisite : prerequisites) {
            int to = prerequisite[0];
            int from = prerequisite[1];
            graph.computeIfAbsent(from, ArrayList<Integer>::new).add(to);
        }

        for (int i = 0; i < numCourses; ++i) {
            if (visited[i] == 0 && !isAcyclicDfsFromNode(graph, visited, i, path)) {
                return new int[]{};
            }
        }

        int[] res = new int[numCourses];
        int ind = numCourses;
        for(int course:path){
            res[--numCourses] = course;
        }
        return res;
    }

    private boolean isAcyclicDfsFromNode(Map<Integer, List<Integer>> graph, int[] visited, int node, List<Integer> path) {
        if(visited[node] == 2) {
            return true;
        }
        visited[node] = 1;
        List<Integer> neighbors = graph.getOrDefault(node, new ArrayList<>());
        for (int neighbor : neighbors) {
            if (visited[neighbor] == 1) {
                return false;
            }
            if (!isAcyclicDfsFromNode(graph, visited, neighbor, path)) {
                return false;
            }
        }
        visited[node] = 2;
        path.add(node);
        return true;
    }
}
//leetcode submit region end(Prohibit modification and deletion)
