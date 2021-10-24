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
// Return true if you can finish all courses. Otherwise, return false. 
//
// 
// Example 1: 
//
// 
//Input: numCourses = 2, prerequisites = [[1,0]]
//Output: true
//Explanation: There are a total of 2 courses to take. 
//To take course 1 you should have finished course 0. So it is possible.
// 
//
// Example 2: 
//
// 
//Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
//Output: false
//Explanation: There are a total of 2 courses to take. 
//To take course 1 you should have finished course 0, and to take course 0 you 
//should also have finished course 1. So it is impossible.
// 
//
// 
// Constraints: 
//
// 
// 1 <= numCourses <= 10⁵ 
// 0 <= prerequisites.length <= 5000 
// prerequisites[i].length == 2 
// 0 <= ai, bi < numCourses 
// All the pairs prerequisites[i] are unique. 
// 
// Related Topics Depth-First Search Breadth-First Search Graph Topological 
//Sort 👍 7410 👎 300


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
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
            if (neighbors.containsKey(course)) {
                for (int neighbor : neighbors.get(course)) {
                    --degree[neighbor];
                    if (degree[neighbor] == 0) {
                        zeroDegreeCourses.add(neighbor);
                    }
                }
            }
        }
        return learnedCoursesCnt == numCourses;
    }
}

class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        int[] visited = new int[numCourses];

        // course -> its neighbors
        Map<Integer, List<Integer>> graph = new HashMap<>();

        // Process neighbors and degree of each course
        for (int[] prerequisite : prerequisites) {
            int to = prerequisite[0];
            int from = prerequisite[1];
            graph.computeIfAbsent(from, ArrayList<Integer>::new).add(to);
        }

        for (int i = 0; i < numCourses; ++i) {
            if (visited[i] == 0 && !isAcyclicDfsFromNode(graph, visited, i)) {
                return false;
            }
        }
        return true;
    }

    private boolean isAcyclicDfsFromNode(Map<Integer, List<Integer>> graph, int[] visited, int node) {
        if(visited[node] == 2){
            return true;
        }

        visited[node] = 1;
        List<Integer> neighbors = graph.getOrDefault(node, new ArrayList<>());
        for (int neighbor : neighbors) {
            if (visited[neighbor] == 1) {
                return false;
            }
            if (!isAcyclicDfsFromNode(graph, visited, neighbor)) {
                return false;
            }
        }
        visited[node] = 2;
        return true;
    }
}
//leetcode submit region end(Prohibit modification and deletion)
