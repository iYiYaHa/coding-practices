/*
 * @lc app=leetcode id=399 lang=java
 *
 * [399] Evaluate Division
 *
 * https://leetcode.com/problems/evaluate-division/description/
 *
 * algorithms
 * Medium (51.17%)
 * Likes:    3107
 * Dislikes: 245
 * Total Accepted:    168K
 * Total Submissions: 311.2K
 * Testcase Example:  '[["a","b"],["b","c"]]\n' +
  '[2.0,3.0]\n' +
  '[["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]'
 *
 * You are given an array of variable pairs equations and an array of real
 * numbers values, where equations[i] = [Ai, Bi] and values[i] represent the
 * equation Ai / Bi = values[i]. Each Ai or Bi is a string that represents a
 * single variable.
 * 
 * You are also given some queries, where queries[j] = [Cj, Dj] represents the
 * j^th query where you must find the answer for Cj / Dj = ?.
 * 
 * Return the answers to all queries. If a single answer cannot be determined,
 * return -1.0.
 * 
 * Note: The input is always valid. You may assume that evaluating the queries
 * will not result in division by zero and that there is no contradiction.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries =
 * [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
 * Output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]
 * Explanation: 
 * Given: a / b = 2.0, b / c = 3.0
 * queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
 * return: [6.0, 0.5, -1.0, 1.0, -1.0 ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: equations = [["a","b"],["b","c"],["bc","cd"]], values =
 * [1.5,2.5,5.0], queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
 * Output: [3.75000,0.40000,5.00000,0.20000]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: equations = [["a","b"]], values = [0.5], queries =
 * [["a","b"],["b","a"],["a","c"],["x","y"]]
 * Output: [0.50000,2.00000,-1.00000,-1.00000]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= equations.length <= 20
 * equations[i].length == 2
 * 1 <= Ai.length, Bi.length <= 5
 * values.length == equations.length
 * 0.0 < values[i] <= 20.0
 * 1 <= queries.length <= 20
 * queries[i].length == 2
 * 1 <= Cj.length, Dj.length <= 5
 * Ai, Bi, Cj, Dj consist of lower case English letters and digits.
 * 
 * 
 */

// @lc code=start
class Solution {
    class UnionFind {
        HashMap<String, String> parent;
        HashMap<String, Integer> size;
        HashMap<String, Double> valueTable;

        public UnionFind() {
            parent = new HashMap<>();
            size = new HashMap<>();
            valueTable = new HashMap<>();
        }

        public void union(String a, String b, Double value) {
            createIfNotExist(a);
            createIfNotExist(b);
            String rootA = getRoot(a);
            String rootB = getRoot(b);

            if (rootA.equals(rootB))
                return;
            Integer sizeA = size.get(a);
            Integer sizeB = size.get(b);

            Double valueA = valueTable.get(a);
            Double valueB = valueTable.get(b);

            if (sizeA <= sizeB) {
                parent.put(rootA, rootB);
                size.put(rootB, sizeA + sizeB);
                valueTable.put(rootA, valueB * value / valueA);
            } else {
                parent.put(rootB, rootA);
                size.put(rootA, sizeA + sizeB);
                valueTable.put(rootB, valueA / value / valueB);
            }
        }

        public double query(String a, String b) {
            String rootA = getRoot(a);
            String rootB = getRoot(b);
            if (rootA != null && rootB != null && rootA.equals(rootB)) {
                Double valueA = valueTable.get(a);
                Double valueB = valueTable.get(b);
                return valueA / valueB;
            }
            return -1;
        }

        private String getRoot(String val) {
            if (parent.get(val) == null)
                return null;

            if (val.equals(parent.get(val))) {
                return val;
            } else {
                String oldParent = parent.get(val);
                parent.put(val, getRoot(oldParent));
                valueTable.put(val, valueTable.get(val) * valueTable.get(oldParent));
                return parent.get(val);
            }
        }

        private void createIfNotExist(String val) {
            if (!parent.containsKey(val)) {
                parent.put(val, val);
                size.put(val, 1);
                valueTable.put(val, 1.0);
            }
        }

    }

    public double[] calcEquation(List<List<String>> equations, double[] values, List<List<String>> queries) {
        if (equations == null || values == null || queries == null)
            return new double[] {};

        UnionFind uf = new UnionFind();
        int ind = 0;
        for (List<String> equation : equations) {
            String a = equation.get(0), b = equation.get(1);
            uf.union(a, b, values[ind]);
            ++ind;
        }

        double[] res = new double[queries.size()];
        ind = 0;
        for (List<String> query : queries) {
            String a = query.get(0), b = query.get(1);
            res[ind++] = uf.query(a, b);
        }
        return res;
    }
} 
// @lc code=end
