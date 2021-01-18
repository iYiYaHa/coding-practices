/*
 * @lc app=leetcode id=765 lang=java
 *
 * [765] Couples Holding Hands
 *
 * https://leetcode.com/problems/couples-holding-hands/description/
 *
 * algorithms
 * Hard (54.18%)
 * Likes:    929
 * Dislikes: 66
 * Total Accepted:    30.7K
 * Total Submissions: 55.5K
 * Testcase Example:  '[0,2,1,3]'
 *
 * 
 * N couples sit in 2N seats arranged in a row and want to hold hands.  We want
 * to know the minimum number of swaps so that every couple is sitting side by
 * side.  A swap consists of choosing any two people, then they stand up and
 * switch seats. 
 * 
 * The people and seats are represented by an integer from 0 to 2N-1, the
 * couples are numbered in order, the first couple being (0, 1), the second
 * couple being (2, 3), and so on with the last couple being (2N-2, 2N-1).
 * 
 * The couples' initial seating is given by row[i] being the value of the
 * person who is initially sitting in the i-th seat.
 * 
 * Example 1:
 * Input: row = [0, 2, 1, 3]
 * Output: 1
 * Explanation: We only need to swap the second (row[1]) and third (row[2])
 * person.
 * 
 * 
 * Example 2:
 * Input: row = [3, 2, 0, 1]
 * Output: 0
 * Explanation: All couples are already seated side by side.
 * 
 * 
 * 
 * Note:
 * ⁠
 * ⁠len(row) is even and in the range of [4, 60].
 * ⁠row is guaranteed to be a permutation of 0...len(row)-1.
 * 
 */

// @lc code=start
class Solution {
    // Ref:
    // https://leetcode.com/problems/couples-holding-hands/discuss/113369/Formal-proof-of-the-optimality-of-greedy-algorithm
    public int minSwapsCouples(int[] row) {
        if (row == null || row.length <= 0)
            return 0;

        int[] pos = new int[row.length];
        for (int i = 0; i < row.length; ++i) {
            pos[row[i]] = i;
        }

        int cnt = 0;
        for (int i = 0; i < row.length; i += 2) {
            int honey = row[i] % 2 == 0 ? row[i] + 1 : row[i] - 1;
            if (row[i + 1] != honey) {
                swap(row, pos, i + 1, honey);
                ++cnt;
            }
        }
        return cnt;
    }

    public void swap(int[] row, int[] pos, int i, int target) {
        int j = pos[target];
        int tmp = row[i];
        row[i] = row[j];
        row[j] = tmp;
        pos[row[i]] = i;
        pos[row[j]] = j;
    }
}

class Solution {
    class UnionFind {
        private int[] parent;
        private int[] size;
        private int cnt;

        public UnionFind(int n) {
            parent = new int[n];
            for (int i = 0; i < n; ++i) {
                parent[i] = i;
            }
            size = new int[n];
            cnt = n;
        }

        public void union(int i, int j) {
            int rootI = getRoot(i);
            int rootJ = getRoot(j);
            if (rootI == rootJ)
                return;
            --cnt;
            int sizeI = size[rootI];
            int sizeJ = size[rootJ];
            if (sizeI <= sizeJ) {
                parent[rootI] = rootJ;
                size[rootI] += size[rootJ];
            } else {
                parent[rootJ] = rootI;
                size[rootJ] += size[rootI];
            }
        }

        public int getRoot(int i) {
            if (i != parent[i])
                parent[i] = getRoot(parent[i]);
            return parent[i];
        }
    }

    public int minSwapsCouples(int[] row) {
        if (row == null || row.length <= 0)
            return 0;

        UnionFind uf = new UnionFind(row.length / 2);
        int[] pos = new int[row.length];
        for (int i = 0; i < row.length; ++i) {
            pos[row[i]] = i;
        }

        for (int i = 0; i < row.length; i += 2) {
            uf.union(row[i] / 2, row[i + 1] / 2);
        }
        return row.length / 2 - uf.cnt;
    }
}
// @lc code=end
