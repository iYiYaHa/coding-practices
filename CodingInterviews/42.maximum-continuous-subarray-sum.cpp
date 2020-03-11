#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int sum = 0;
        int maxSum = std::numeric_limits<int>::min();
        for(int num:array){
            if(sum>=0){
                sum += num;
            }else{
                sum = num;
            }
            maxSum = max(sum,maxSum);
        }
        return maxSum;
    }
};

int main(){
    Solution s;
    assert(s.FindGreatestSumOfSubArray({6,-3,-2,7,-15,1,2,2}) == 8);
    assert(s.FindGreatestSumOfSubArray({1,-2,3,10,-4,7,2,-5}) == 18);
    assert(s.FindGreatestSumOfSubArray({-2,-8,-1,-5,-9}) == -1);
}