//Given an integer array nums with possible duplicates, randomly output the 
//index of a given target number. You can assume that the given target number must 
//exist in the array. 
//
// Implement the Solution class: 
//
// 
// Solution(int[] nums) Initializes the object with the array nums. 
// int pick(int target) Picks a random index i from nums where nums[i] == 
//target. If there are multiple valid i's, then each index should have an equal 
//probability of returning. 
// 
//
// 
// Example 1: 
//
// 
//Input
//["Solution", "pick", "pick", "pick"]
//[[[1, 2, 3, 3, 3]], [3], [1], [3]]
//Output
//[null, 4, 0, 2]
//
//Explanation
//Solution solution = new Solution([1, 2, 3, 3, 3]);
//solution.pick(3); // It should return either index 2, 3, or 4 randomly. Each 
//index should have equal probability of returning.
//solution.pick(1); // It should return 0. Since in the array only nums[0] is 
//equal to 1.
//solution.pick(3); // It should return either index 2, 3, or 4 randomly. Each 
//index should have equal probability of returning.
// 
//
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 2 * 10⁴ 
// -2³¹ <= nums[i] <= 2³¹ - 1 
// target is an integer from nums. 
// At most 10⁴ calls will be made to pick. 
// 
// Related Topics Hash Table Math Reservoir Sampling Randomized 👍 777 👎 919


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {

    private int[] nums;
    private Random random;

    public Solution(int[] nums) {
        this.nums = nums;
        this.random = new Random();
    }

    public int pick(int target) {
        int ans = -1;
        for (int i = 0, cnt = 0; i < nums.length; ++i) {
            if (nums[i] == target) {
                ++cnt;
                int randomNum = random.nextInt(cnt);
                if (randomNum <= 0) {
                    ans = i;
                }
            }
        }
        return ans;
    }
}

class Solution {

    private Map<Integer, List<Integer>> inverseIndex;
    private Random random;

    public Solution(int[] nums) {
        this.inverseIndex = new HashMap<>();
        for(int i = 0;i < nums.length; ++i){
            inverseIndex.computeIfAbsent(nums[i], num->new ArrayList<Integer>()).add(i);
        }
        this.random = new Random();
    }

    public int pick(int target) {
        List<Integer> indexList = inverseIndex.get(target);
        int randomInd = random.nextInt(indexList.size());
        return indexList.get(randomInd);
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
//leetcode submit region end(Prohibit modification and deletion)
