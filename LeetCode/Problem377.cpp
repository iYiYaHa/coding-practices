//Problem : Combination Sum IV
//
//Problem Description:
//  Given an integer array with all positive numbers and no duplicates, 
//  find the number of possible combinations that add up to a positive integer target.
//  
//  Example1:
//  nums = [1, 2, 3]
//  target = 4
//  
//  The possible combination ways are :
//  (1, 1, 1, 1)
//  (1, 1, 2)
//  (1, 2, 1)
//  (1, 3)
//  (2, 1, 1)
//  (2, 2)
//  (3, 1)
//  
//  Note that different sequences are counted as different combinations.
//  
//  Therefore the output is 7.


#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
	int combinationSum4(std::vector<int>& nums, int target) {
		std::vector<long> dp(target + 1, 0);
		dp[0] = 1;
		for (int i = 1; i <= target; ++i) {
			for (int num : nums)
				if (i >= num)
					dp[i] += dp[i - num];
		}
		return dp[target];
	}
};
int main() {
	Solution solution;
	std::vector<std::pair<std::vector<int>, int>> testCase = { {{1, 2, 3},4} };
	std::vector<int> testAns = { 7 };
	for (int i = 0; i < testCase.size(); ++i) {
		bool result = solution.combinationSum4(testCase[i].first, testCase[i].second) == testAns[i];
		if (result)
			std::cout << "Test case " << i + 1 << " passed." << std::endl;
		else
			std::cout << "Test case " << i + 1 << " failed." << std::endl;
	}
	std::cin.get();
	return 0;
}