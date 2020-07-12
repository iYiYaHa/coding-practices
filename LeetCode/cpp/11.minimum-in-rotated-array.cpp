
class SolutionA {
public:
    int minArray(vector<int>& numbers) {
        int left = 0, right = numbers.size()-1;
        while(left<right){
            if(numbers[left]<numbers[right])break;// 相当于分情况讨论。这种情况就是没旋转的。
            int mid = left + (right-left)/2;
            if(numbers[left]<numbers[mid]){
                left=mid+1;
            }else if(numbers[left]>numbers[mid]){
                right=mid;
            }else{
                ++left;
            }
        }
        return numbers[left];
    }
};

// ref:https://leetcode-cn.com/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/solution/mian-shi-ti-11-xuan-zhuan-shu-zu-de-zui-xiao-shu-3/
// 旋转点是右半边数组的最小值。
// left 不一定是左半边的数组中的。但 right 一定在右半边的数组中。
class SolutionB {
public:
    int minArray(vector<int>& numbers) {
        int left = 0, right = numbers.size()-1;
        while(left<right){
            int mid = left + (right-left)/2;
            if(numbers[right]<numbers[mid]){
                left=mid+1;
            }else if(numbers[right]>numbers[mid]){
                right=mid;
            }else{
                --left;
            }
        }
        return numbers[left];
    }
};