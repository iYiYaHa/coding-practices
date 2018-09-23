////A sequence of number is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.
////
////For example, these are arithmetic sequence :
////
////1, 3, 5, 7, 9
////7, 7, 7, 7
////3, -1, -5, -9
////The following sequence is not arithmetic.
////
////1, 1, 2, 5, 7
////
////A zero - indexed array A consisting of N numbers is given.A slice of that array is any pair of integers(P, Q) such that 0 <= P < Q < N.
////
////	A slice(P, Q) of array A is called arithmetic if the sequence :
////A[P], A[p + 1], ..., A[Q - 1], A[Q] is arithmetic.In particular, this means that P + 1 < Q.
////
////	The function should return the number of arithmetic slices in the array A.
////
////
////	Example :
////
////	A = [1, 2, 3, 4]
////
////	return : 3, for 3 arithmetic slices in A : [1, 2, 3], [2, 3, 4] and [1, 2, 3, 4] itself.
//#include<iostream>
//#include<vector>
//
//using std::vector;
//using std::cin;
//using std::cout;
//using std::endl;
//class Solution {
//public:
//
//	////Using formula with time complexity O(n) and space complexity O(1)
//	//int numberOfArithemticSlices(vector<int> &A) {
//	//	int count = 0, sum = 0;
//	//	for (size_t i = 2; i < A.size(); ++i) {
//	//		if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
//	//			++count;
//	//		}
//	//		else {
//	//			sum += count * (count + 1) / 2;
//	//			count = 0;
//	//		}
//	//	}
//	//	return sum;
//	//}
//
//	//// Dynamic Programming with time complexity O(n) and space complexity O(1).
//	//// dp[j] denote #arithemtic sequence from A[0] to A[j].
//	//// dp[j] = k-1 + d[j-1] if(A[j] - A[j-1] == A[j-1] - A[j-2]) d[j-1] otherwise.
//	//// k here denote the longest arithemtic subsequence with A[j-1] as tail,that is,
//	//// A[j-k] to A[j-1] is a arithemtic sequence.
//	//// With further optimization, we can use only one extra variable to store dp[i];
//	//int numberOfArithmeticSlices(vector<int>& A) {
//	//	int count = 0, dp = 0;
//	//	for (size_t i = 2, count = 2; i < A.size(); ++i) {
//	//		if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
//	//			dp = count - 1 + dp;
//	//			++count;
//	//		}
//	//		else {
//	//			count = 2;
//	//		}
//	//	}
//	//	return dp;
//	//}
//	
//	////Dynamic Programming with time complexity O(n) and space complexity O(n)
//	//int numberOfArithemticSlices(vector<int> &A) {
//	//	vector<int> dp(A.size(), 0);
//	//	int sum = 0;
//	//	for (size_t i = 2; i < A.size(); ++i) {
//	//		if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
//	//			dp[i] = 1 + dp[i + 1];
//	//			sum += dp[i];
//	//		}
//	//	}
//	//	return sum;
//	//}
//
//	//int numberOfArithmeticSlices(vector<int>& A) {
//	//	const int length = A.size();
//	//	int count = 0;
//	//	vector<int> dp(length, 0);
//	//	for (int i = 0; i < length; ++i) {
//	//		dp[i] = 1;
//	//		if (i < length - 1)
//	//			dp[i + 1] = 2;
//	//		for (int j = i + 2; j < length; ++j) {
//	//			dp[j] = A[j] - A[j - 1] == A[j - 1] - A[j - 2] ? dp[j - 1] + 1 : 0;
//	//			count = dp[j] >= 3 ? count + 1 : count;
//	//		}
//	//	}
//	//	return count;
//	//}
//
//	////Fake Dynamic Programming,with space complexity optimized to O(n),time complexity O(n^2)
//	//int numberOfArithmeticSlices(vector<int>& A) {
//	//	const int length = A.size();
//	//	int count = 0;
//	//	vector<int> dp(length, 0);
//	//	for (int i = 0; i < length; ++i) {
//	//		dp[i] = 1;
//	//		if (i < length - 1)
//	//		dp[i + 1] = 2;
//	//		for (int j = i + 2; j < length; ++j) {
//	//			dp[j] = A[j] - A[j - 1] == A[j - 1] - A[j - 2]? dp[j - 1] + 1:0;
//	//			count = dp[j] >= 3 ? count + 1 : count;
//	//		}
//	//	}
//	//	return count;
//	//}
//
//	////Dynamic Programming, memory limit exceed.
//	//int numberOfArithmeticSlices(vector<int>& A) {
//	//	const int length = A.size();
//	//	int count = 0;
//	//	vector<vector<int>> dp(length, vector<int>(length, 0));
//	//	for (int i = 0; i < length; ++i) {
//	//		dp[i][i] = 1;
//	//		if (i < length - 1)
//	//			dp[i][i + 1] = 2;
//	//		for (int j = i+2; j < length; ++j) {
//	//			if (A[j] - A[j - 1] == A[j - 1] - A[j - 2])
//	//				dp[i][j] = dp[i][j - 1] + 1;
//	//			else
//	//				dp[i][j] = 0;
//	//			count = dp[i][j] >= 3 ? count + 1 : count;
//	//		}
//	//	}
//	//	return count;
//	//}
//};
//int main() {
//	int num = 0;
//	vector<int> nums;
//	Solution solution;
//	while (std::cin >> num) {
//		nums.clear();
//		nums.push_back(num);
//		while (std::cin >> num)
//			nums.push_back(num);
//		cin.clear();
//		cin.ignore();
//		std::cout << solution.numberOfArithmeticSlices(nums) << std::endl;
//	}
//	return 0;
//}