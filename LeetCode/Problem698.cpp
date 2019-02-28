//#include<vector>
//#include<functional>
//#include<numeric>
//#include<algorithm>
//#include<iostream>
//
//class SolutionA {
//private:
//	bool helper(std::vector<int> &nums, int k, int sum, int target) {
//		if (k == 1)
//			return true;
//		if (sum == target)
//			return helper(nums, k - 1, 0, target);
//		for (int i = 0; i < nums.size(); ++i) {
//			if (nums[i] == 0 || (sum + nums[i] > target))
//				continue;
//			int tmp = nums[i];
//			nums[i] = 0;
//			if (helper(nums, k, sum + tmp, target)) return true;
//			nums[i] = tmp;
//		}
//		return false;
//	}
//public:
//	bool canPartitionKSubsets(std::vector<int>& nums, int k) {
//		if (k == 1) return true;
//		int sum = std::accumulate(nums.begin(), nums.end(), 0, [](int a, int b) {return a + b; });
//		std::sort(nums.begin(), nums.end(), std::greater<int>());
//
//		// Impossible under following circumstances.
//		// k <= 0 invalid input
//		// sum can not be divided by k
//		// The largest number is bigger than sum/k
//		if (k <= 0 || sum % k != 0 || nums[0] > (sum / k)) return false;
//
//		return helper(nums, k, 0, sum / k);
//	}
//};
//
//class SolutionB {
//	// Put all numbers into k bins staisfying the sum of each bin is sum/k
//private:
//	bool helper(const std::vector<int> &nums, int idx, std::vector<int> &bins, int target) {
//		if (idx >= nums.size())
//			return true;
//		for (int i = 0; i < bins.size(); ++i) {
//			if (bins[i] + nums[idx] <= target) {
//				bins[i] += nums[idx];
//				if (helper(nums, idx + 1, bins, target)) return true;
//				bins[i] -= nums[idx];
//			}
//		}
//		return false;
//	}
//public:
//	bool canPartitionKSubsets(std::vector<int>& nums, int k) {
//		if (k == 1) return true;
//		int sum = std::accumulate(nums.begin(), nums.end(), 0);
//		std::sort(nums.begin(), nums.end(), std::greater<int>());
//
//		// Impossible under following circumstances.
//		// k <= 0 invalid input
//		// sum can not be divided by k
//		// The largest number is bigger than sum/k
//		if (k <= 0 || sum % k != 0 || nums[0] > (sum / k)) return false;
//		std::vector<int> bins(k, 0);
//		return helper(nums, 0, bins, sum / k);
//	}
//};
//int main() {
//	std::vector<std::pair<std::vector<int>, int>> testCase = { {{15, 3557, 42, 3496, 5, 81, 34, 95, 9, 81, 42, 106, 71},11} };
//		std::vector<bool> testAns = { false };
//		for (int i = 0; i < testCase.size(); ++i) {
//			bool result = SolutionA().canPartitionKSubsets(testCase[i].first,testCase[i].second) == testAns[i];
//			if (result)
//				std::cout << "Test case " << i + 1 << " passed with solution A." << std::endl;
//			else
//				std::cout << "Test case " << i + 1 << " failed with solution A." << std::endl;
//		}
//		std::cin.get();
//		return 0;
//}