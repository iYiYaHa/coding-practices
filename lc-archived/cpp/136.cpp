//#include<iostream>
//#include<vector>
//
//class Solution {
//public:
//	int singleNumber(std::vector<int>& nums) {
//		int a = 0;
//		for (int &i : nums) {
//			a = a ^ i;
//		}
//		return a;
//	}
//};
//
//int main() {
//	std::vector<std::vector<int>> testCase = { {2,2,3} };
//	std::vector<int> testAns = { 3 };
//	for (int i = 0; i < testCase.size(); ++i) {
//		bool result = Solution().singleNumber(testCase[i]) == testAns[i];
//		if (result)
//			std::cout << "Test case " << i + 1 << " passed with solution A." << std::endl;
//		else
//			std::cout << "Test case " << i + 1 << " failed with solution A." << std::endl;
//	}
//	std::cin.get();
//	return 0;
//}