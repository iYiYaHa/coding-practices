#include<iostream>
#include<vector>

class SolutionA {
	// Time Complexity: O(32n) = O(n)
public:
	int singleNumber(std::vector<int>& nums) {
		int ans = 0;
		for (int i = 0; i < 32; ++i) {// Traverse each bit
			int count = 0;				// Recording the number of numbers whose ith bit is 1
			for (const int num : nums) {// Traverse every number and judge whether ith bit is 1
				if ((1 << i) & num)
					count += 1;
			}
			count %= 3;					// Model 3 to filter all numbers appearing three times.
			if (count != 0)
				ans |= (1 << i);
		}
		return ans;
	}
};

int main() {
	std::vector<std::vector<int>> testCase = { {2,2,2,3} };
	std::vector<int> testAns = { 3 };
	for (int i = 0; i < testCase.size(); ++i) {
		bool result = SolutionA().singleNumber(testCase[i]) == testAns[i];
		if (result)
			std::cout << "Test case " << i + 1 << " passed with solution A." << std::endl;
		else
			std::cout << "Test case " << i + 1 << " failed with solution A." << std::endl;
	}
	std::cin.get();
	return 0;
}