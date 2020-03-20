
class SolutionA {
public:
    int minArray(vector<int>& numbers) {
        int left = 0, right = numbers.size()-1;
        while(left<right){
            if(numbers[left]<numbers[right])break;
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