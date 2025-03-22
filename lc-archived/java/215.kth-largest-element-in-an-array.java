/*
 * @lc app=leetcode id=215 lang=java
 *
 * [215] Kth Largest Element in an Array
 */

// @lc code=start
class Solution {
    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> queue = new PriorityQueue<>();
        for(int num:nums){
            queue.add(num);
            if(queue.size()>k){
                queue.poll();
            }
        }
        return queue.peek();
    }
}

class Solution {
    public int findKthLargest(int[] nums, int k) {
        return quickSelect(nums, 0, nums.length-1, nums.length-k);
    }

    private int quickSelect(int[] nums, int beg, int end, int k){
        int pivotInd = partition(nums,beg,end);
        if(pivotInd == k)return nums[k];
        else if(pivotInd>k)return quickSelect(nums, beg,pivotInd-1,k);
        else return quickSelect(nums, pivotInd+1,end,k);
    }

    private int partition(int[] nums, int beg, int end){
        int pivot = nums[beg];
        int pivotInd = beg+1;
        for(int i = beg+1;i<=end;++i){
            if(nums[i]<=pivot){
                swap(nums,pivotInd++,i);
            }
        }
        swap(nums, beg, --pivotInd);
        return pivotInd;
    }

    private void swap(int[] nums, int i, int j){
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
}
// @lc code=end

