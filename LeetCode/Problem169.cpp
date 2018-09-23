////Problem: Majority Elements
////Problem Description:
////        Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
////        You may assume that the array is non - empty and the majority element always exist in the array.
////
////        Example 1:
////        Input: [3, 2, 3]
////	      Output : 3
////
////	      Example 2 :
////        Input : [2, 2, 1, 1, 1, 2, 2]
////	      Output : 2
//
//#include <vector>
//#include <iostream>
//
//class Solution {
//public:
//	int majorityElement(std::vector<int>& nums) {
//		return 0;
//	}
//};
//
//int main() {
//	Solution solution;
//	std::vector<std::vector<int>> tests;
//	std::vector<int> test1 = { 3,2,3 };
//	std::vector<int> test2 = { 2,2,1,1,1,2,2 };
//	tests.push_back(test1);
//	tests.push_back(test2);
//
//	for (size_t i = 0; i < tests.size(); ++i) {
//		std::cout << "Test" << i + 1;
//		std::cout << ":{";
//		for (int num : tests[i]) {
//			std::cout <<" "<<num ;
//		}
//		std::cout << "}";
//		std::cout << " answer:" << solution.majorityElement(tests[i]) << std::endl;
//	}
//	std::cin.get();
//	return 0;
//}