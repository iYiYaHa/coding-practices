class Solution {
    public int minArray(int[] numbers) {
        int left = 0, right = numbers.length-1;
        // Find the minimum of the right part.
        while(left < right && numbers[left]>=numbers[right]){
            int mid = left + (right-left)/2;
            if(numbers[mid] > numbers[right]){
                left=mid+1;
            }else if(numbers[mid] == numbers[right]){
                --right;
            }else{// <
                right=mid;
            }
        }
        return numbers[left];
    }
}

class Solution {
    public int minArray(int[] nums) {
        if(nums == null || nums.length <= 0)
            return 0;
        int left = 0, right = nums.length - 1;
        while(left < right){
            if(nums[left] < nums[right])
                break;
            int mid = left + (right-left)/2;
            if(nums[left] > nums[mid]){
                right = mid;
            }else if(nums[left] < nums[mid]){
                left = mid + 1;
            }else{
                ++left;
            }
        }
        return nums[left];
    }
}