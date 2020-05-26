class SolutionA {
    public int findRepeatNumber(int[] nums) {
        Set<Integer> set = new HashSet<>();
        for(int num:nums){
            if(!set.contains(num))
                set.add(num);
            else
                return num;
        }
        return -1;
    }
}

class SolutionB {
    public int findRepeatNumber(int[] nums) {
        for(int i = 0;i < nums.length;){
            if(nums[i] == i)
                ++i;
            else{
                int pos = nums[i];
                if(nums[i] != nums[pos]){
                    int tmp = nums[i];
                    nums[i] = nums[pos];
                    nums[pos] = tmp;
                }
                else{
                    return nums[i];
                }
            }
        }
        return -1;
    }
}

class Solution {
    public int findRepeatNumber(int[] nums) {
        for(int i = 0;i < nums.length;++i){
            while(nums[i] != i){
                int pos = nums[i];
                if(nums[i] == nums[pos])
                    return nums[i];
                else{
                    int tmp = nums[i];
                    nums[i] = nums[pos];
                    nums[pos] = tmp;
                }   
            }
        }
        return -1;
    }
}