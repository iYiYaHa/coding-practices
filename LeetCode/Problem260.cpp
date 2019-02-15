#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<numeric>

class Solution {
public:
	std::vector<int> singleNumber(std::vector<int>& nums) {
		int xorRes = std::accumulate(nums.begin(), nums.end(), 0, std::bit_xor<int>());
		int a = 0;
		for (const int &num : nums) {
			if (num&xorRes&~(xorRes - 1))//xorRes & ~(xorRes-1) == xorRes & (-xorRes)
				a ^= num;
		}
		return std::vector<int>{a, xorRes^a};
	}
};

int main() {
	std::vector<std::vector<int>> testCase = { {1,2,1,3,2,5} };
	std::vector<std::vector<int>> testAns = { {3,5} };
	for (int i = 0; i < testCase.size(); ++i) {
		bool result = Solution().singleNumber(testCase[i]) == testAns[i];
		if (result)
			std::cout << "Test case " << i + 1 << " passed with solution A." << std::endl;
		else
			std::cout << "Test case " << i + 1 << " failed with solution A." << std::endl;
	}
	std::cin.get();
	return 0;
}