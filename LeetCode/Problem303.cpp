//// Problem : Range Sum Query - Immutable
////
//// Problem Description:
////  Given an integer array nums, find the sum of the elements between indices i and j (i ¡Ü j), inclusive.
////
//// Example:
////  Given nums = [-2, 0, 3, -5, 2, -1]
////
////  sumRange(0, 2) -> 1
////  sumRange(2, 5) -> - 1
////  sumRange(0, 5) -> - 3
////
////  Note:
////  1.You may assume that the array does not change.
//// 2.There are many calls to sumRange function.
//
//#include<iostream>
//#include<vector>
//
//class NumArray {
//private:
//	std::vector<int> sum;
//public:
//	NumArray(std::vector<int> nums) :sum(nums.size()+1, 0) {
//		sum[0] = 0;
//		for (int i = 1; i < sum.size(); ++i) {
//			sum[i] = sum[i-1] + nums[i-1];
//		}
//	}
//
//	int sumRange(int i, int j) {
//		return sum[j+1] - sum[i];
//	}
//};
//
///**
//* Your NumArray object will be instantiated and called as such:
//* NumArray obj = new NumArray(nums);
//* int param_1 = obj.sumRange(i,j);
//*/
//
//int main()
//{
//	std::vector < std::vector<int>> testCase = { { -8261, 2300, -1429, 6274, 9650, -3267, 1414, -8102, 6251, -5979, -5291, -4616, -4703 } };
//	NumArray obj(testCase[0]);
//	std::vector<int> testAns = { 1,-1,-3 }; //[0, 2], [2, 5], [0, 5]
//	bool passFlag = true;
//	passFlag &= obj.sumRange(0, 2) == 1;
//	passFlag &= obj.sumRange(2, 5) == -1;
//	passFlag &= obj.sumRange(0, 5) == -3;
//	std::cout << passFlag << std::endl;
//	std::cin.get();
//	return 0;
//}