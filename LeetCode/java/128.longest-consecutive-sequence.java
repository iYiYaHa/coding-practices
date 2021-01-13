/*
 * @lc app=leetcode id=128 lang=java
 *
 * [128] Longest Consecutive Sequence
 *
 * https://leetcode.com/problems/longest-consecutive-sequence/description/
 *
 * algorithms
 * Hard (44.82%)
 * Likes:    4476
 * Dislikes: 218
 * Total Accepted:    362K
 * Total Submissions: 786.4K
 * Testcase Example:  '[100,4,200,1,3,2]'
 *
 * Given an unsorted array of integers nums, return the length of the longest
 * consecutive elements sequence.
 * 
 * Follow up: Could you implement the O(n) solution? 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [100,4,200,1,3,2]
 * Output: 4
 * Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
 * Therefore its length is 4.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [0,3,7,2,5,8,4,6,0,1]
 * Output: 9
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= nums.length <= 10^4
 * -10^9 <= nums[i] <= 10^9
 * 
 * 
 */

// @lc code=start
class Solution {
    class UnionFind {
        HashMap<Integer, Integer> parent;
        HashMap<Integer, Integer> size;
        int largestSize;

        UnionFind() {
            parent = new HashMap<>();
            size = new HashMap<>();
            largestSize = 0;
        }

        public int getLargestSize() {
            return largestSize;
        }

        public boolean containsElement(int num) {
            return parent.containsKey(num);
        }

        public void addElement(int num) {
            if (!parent.containsKey(num)) {
                parent.put(num, num);
                size.put(num, 1);
                largestSize = Math.max(largestSize, 1);
            }
        }

        public void union(int i, int j) {
            if (parent.containsKey(i) && parent.containsKey(j)) {
                int rootI = root(i);
                int rootJ = root(j);
                if (rootI == rootJ)
                    return;
                int sizeI = size.get(rootI);
                int sizeJ = size.get(rootJ);
                if (sizeI <= sizeJ) {
                    parent.put(rootI, rootJ);
                    size.put(rootJ, sizeI + sizeJ);
                } else {
                    parent.put(rootJ, rootI);
                    size.put(rootI, sizeI + sizeJ);
                }
                largestSize = Math.max(largestSize, sizeI + sizeJ);
            }
        }

        public int root(int i) {
            while (i != parent.get(i)) {
                int parentI = parent.get(i);
                parent.put(i, parent.get(parentI));
                i = parent.get(i);
            }
            return i;
        }
    }

    public int longestConsecutive(int[] nums) {
        if (nums == null || nums.length <= 0)
            return 0;
        UnionFind uf = new UnionFind();
        for (int num : nums) {
            uf.addElement(num);
            if (uf.containsElement(num + 1)) {
                uf.union(num, num + 1);
            }
            if (uf.containsElement(num - 1)) {
                uf.union(num, num - 1);
            }
        }
        return uf.getLargestSize();
    }
}

class Solution {
    public int longestConsecutive(int[] nums) {
        if (nums == null || nums.length <= 0)
            return 0;

        Set<Integer> set = new HashSet<>();
        for (int num : nums) {
            set.add(num);
        }

        int ans = 0;
        for (int num : set) {
            if (!set.contains(num - 1)) { // Has been count
                int curNum = num;
                int cnt = 1;
                while (set.contains(curNum + 1)) {
                    ++curNum;
                    ++cnt;
                }
                ans = Math.max(ans, cnt);
            }
        }
        return ans;
    }
}

class Solution {
    public int longestConsecutive(int[] nums) {
        if (nums == null || nums.length <= 0)
            return 0;
        HashMap<Integer, Integer> table = new HashMap<>();
        int ans = 0;
        for (int num : nums) {
            if (!table.containsKey(num)) {
                int left = table.containsKey(num - 1) ? table.get(num - 1) : 0;
                int right = table.containsKey(num + 1) ? table.get(num + 1) : 0;
                int len = left + right + 1;

                table.put(num, len);
                table.put(num - left, len);
                table.put(num + right, len);
                ans = Math.max(ans, len);
            }
        }
        return ans;
    }
}
// @lc code=end
