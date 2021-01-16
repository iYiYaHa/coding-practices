/*
 * @lc app=leetcode id=952 lang=java
 *
 * [952] Largest Component Size by Common Factor
 *
 * https://leetcode.com/problems/largest-component-size-by-common-factor/description/
 *
 * algorithms
 * Hard (30.02%)
 * Likes:    534
 * Dislikes: 67
 * Total Accepted:    25K
 * Total Submissions: 69.4K
 * Testcase Example:  '[4,6,15,35]'
 *
 * Given a non-empty array of unique positive integers A, consider the
 * following graph:
 * 
 * 
 * There are A.length nodes, labelled A[0] to A[A.length - 1];
 * There is an edge between A[i] and A[j] if and only if A[i] and A[j] share a
 * common factor greater than 1.
 * 
 * 
 * Return the size of the largest connected component in the graph.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [4,6,15,35]
 * Output: 4
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [20,50,9,63]
 * Output: 2
 * 
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [2,3,6,7,4,12,21,39]
 * Output: 8
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= A.length <= 20000
 * 1 <= A[i] <= 100000
 * 
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
    class UnionFind {
        HashMap<Integer, Integer> parent;
        HashMap<Integer, Integer> size;

        public UnionFind() {
            parent = new HashMap<>();
            size = new HashMap<>();
        }

        public void union(Integer a, Integer b) {
            createIfNotExist(a);
            createIfNotExist(b);
            Integer rootA = getRoot(a);
            Integer rootB = getRoot(b);

            if (rootA.equals(rootB))
                return;
            Integer sizeA = size.get(a);
            Integer sizeB = size.get(b);

            if (sizeA <= sizeB) {
                parent.put(rootA, rootB);
                size.put(rootB, sizeA + sizeB);
            } else {
                parent.put(rootB, rootA);
                size.put(rootA, sizeA + sizeB);
            }
        }

        private Integer getRoot(Integer val) {
            if (parent.get(val) == null)
                return null;

            if (val.equals(parent.get(val))) {
                return val;
            } else {
                Integer oldParent = parent.get(val);
                parent.put(val, getRoot(oldParent));
                return parent.get(val);
            }
        }

        private void createIfNotExist(Integer val) {
            if (!parent.containsKey(val)) {
                parent.put(val, val);
                size.put(val, 1);
            }
        }

    }

    public int largestComponentSize(int[] A) {
        if (A == null || A.length <= 0)
            return 0;

        UnionFind uf = new UnionFind();
        for (int num : A) {
            uf.union(num, num);
            for (int i = 2; i * i <= num; ++i) {
                int left = i;
                int right = num / i;
                if (left * right == num) {
                    uf.union(num, i);
                    uf.union(num, num / i);
                }
            }
        }

        HashMap<Integer, Integer> counter = new HashMap<>();
        int ans = 0;
        for (int num : A) {
            int root = uf.getRoot(num);
            int cnt = counter.getOrDefault(root, 0);
            ++cnt;
            counter.put(root, cnt);
            ans = Math.max(cnt, ans);
        }
        return ans;
    }
}

class Solution {
    class UnionFind {
        int[] parent;
        int[] size;

        public UnionFind(int n) {
            parent = new int[n];
            for (int i = 0; i < n; ++i) {
                parent[i] = i;
            }
            size = new int[n];
        }

        public void union(Integer a, Integer b) {
            Integer rootA = getRoot(a);
            Integer rootB = getRoot(b);

            if (rootA.equals(rootB))
                return;
            Integer sizeA = size[a];
            Integer sizeB = size[b];

            if (sizeA <= sizeB) {
                parent[rootA] = rootB;
                size[rootB] = sizeA + sizeB;
            } else {
                parent[rootB] = rootA;
                size[rootA] = sizeA + sizeB;
            }
        }

        private Integer getRoot(Integer val) {
            if (val == parent[val]) {
                return val;
            } else {
                parent[val] = getRoot(parent[val]);
                return parent[val];
            }
        }
    }

    public int largestComponentSize(int[] A) {
        if (A == null || A.length <= 0)
            return 0;
        int n = Arrays.stream(A).max().getAsInt();
        UnionFind uf = new UnionFind(n + 1);
        for (int num : A) {

            uf.union(num, num);

            for (int i = 2; i * i <= num; ++i) {
                if (num % i == 0) {
                    uf.union(num, i);
                    uf.union(num, num / i);
                }
            }
        }

        HashMap<Integer, Integer> counter = new HashMap<>();
        int ans = 0;
        for (int num : A) {
            int root = uf.getRoot(num);
            int cnt = counter.getOrDefault(root, 0);
            ++cnt;
            counter.put(root, cnt);
            ans = Math.max(cnt, ans);
        }
        return ans;
    }
}
// @lc code=end
