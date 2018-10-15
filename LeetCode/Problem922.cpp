////Problem : Sort Array By Parity II
////
////Problem Description:
////  Given an array A of non-negative integers, half of the integers in A are odd, and 
////  half of the integers are even.
////  
////  Sort the array so that whenever A[i] is odd, i is odd; and whenever A[i] is even, 
////  i is even.
////  
////  You may return any answer array that satisfies this condition.
//
////  Example 1:
////		Input: [4,2,5,7]
////		Output: [4, 5, 2, 7]
////		Explanation : [4, 7, 2, 5], [2, 5, 4, 7], [2, 7, 4, 5] would also have been accepted.
//// 
////  Note :
//// 
////  1. 2 <= A.length <= 20000
////	2. A.length % 2 == 0
////	3. 0 <= A[i] <= 1000
//
//#include <iostream>
//#include <vector>
//#include <string>
//#define max(a,b) ((a)>(b)?(a):(b))
//
//class Solution {
//public:
//	std::vector<int> sortArrayByParityII(std::vector<int>& A) {
//		int evenInd = 0;
//		int oddInd = 1;
//		while (oddInd < A.size() && evenInd < A.size()) {
//			bool oddOkay = A[oddInd] % 2 == 1;
//			bool evenOkay = A[evenInd] % 2 == 0;
//			if (oddOkay && evenOkay) {
//				oddInd += 2;
//				evenInd += 2;
//			}
//			else if (!oddOkay && evenOkay) {
//				evenInd += 2;
//			}
//			else if (oddOkay && !evenOkay) {
//				oddInd += 2;
//			}
//			else {
//				int temp = A[oddInd];
//				A[oddInd] = A[evenInd];
//				A[evenInd] = temp;
//				oddInd += 2;
//				evenInd += 2;
//			}
//		}
//		return A;
//	}
//};
//
//int main() {
//	std::vector<std::vector<int>> testCase = { {4,2,5,7 }};
//	std::vector<std::vector<int>> testAns = { {4,5,2,7} };
//	for (int i = 0; i < testCase.size(); ++i) {
//		bool result = Solution().sortArrayByParityII(testCase[i]) == testAns[i];
//		if (result)
//			std::cout << "Test case " << i + 1 << "passed with solution A." << std::endl;
//		else
//			std::cout << "Test case " << i + 1 << "failed with solution A." << std::endl;
//	}
//	std::cin.get();
//	return 0;
//}