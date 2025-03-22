class SolutionA {
    public int[] exchange(int[] nums) {
        if(nums == null || nums.length == 0)
            return nums;
        for(int i = 0, k = 0;i<nums.length;++i){
            if((nums[i] & 1) != 0){
                int tmp = nums[i];
                nums[i] = nums[k];
                nums[k] = tmp;
                ++k;
            }
        }
        return nums;
    }
}

class SolutionB {
    public int[] exchange(int[] nums) {
        if(nums == null || nums.length == 0)
            return nums;
        int left = 0, right = nums.length-1;
        while(left<right){
            while(left<right &&(nums[left] & 1) != 0)++left;
            while(left<right &&(nums[right] & 1) == 0)--right;
            if(left<right){
                int tmp = nums[left];
                nums[left] = nums[right];
                nums[right] = tmp;
            }
        }
        return nums;
    }
}