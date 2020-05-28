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