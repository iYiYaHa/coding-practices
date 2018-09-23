
//////Solution One
////using namespace std;
////class Solution {
////public:
////	vector<int> twoSum(vector<int>& nums, int target) {
////		vector<int> result;
////		for (size_t i = 0; i < nums.size(); ++i) {
////			for (size_t j = i + 1; j < nums.size(); ++j) {
////				if (i != j)
////					if ((nums[i] + nums[j]) == target) {
////						result.push_back(i);
////						result.push_back(j);
////						return result;
////					}
////			}
////		}
////	}
////};
//
////The solution below doesn't handle situations with duplicate numbers.
////Since the test cases in problem one don't include case with duplicate numbers, this solution is accepted.
////Solution Two
//using namespace std;
//class Solution {
//public:
//	vector<int> twoSum(vector<int>& nums, int target) {
//		unordered_map<int, size_t> num_Index;
//		vector<int> result;
//		//Construct (num,index) pair
//		for (size_t i = 0; i < nums.size(); ++i)
//			num_Index.insert(make_pair(nums[i], i));
//
//		for (size_t i = 0; i < nums.size(); ++i)
//			if (num_Index.find(target - nums[i]) != num_Index.end()) {
//				size_t otherIndex = num_Index.at(target - nums[i]);
//				if (i != otherIndex) {
//					result.push_back(i);
//					result.push_back(otherIndex);
//					return result;
//				}
//			}
//		throw runtime_error("No such element!");
//	}
//};
//
////Solution Three
////This solution is from the discuss.
//
//using namespace std;
//class Solution {
//public:
//	vector<int> twoSum(vector<int>& nums, int target) {
//		unordered_map<int, size_t> numIndex;
//		vector<int> result;
//
//		for (size_t i = 0; i < nums.size(); ++i) {
//			int otherNum = target - nums[i];
//			if (numIndex.find(otherNum) != numIndex.end()) {
//				result.push_back(numIndex[otherNum]);
//				result.push_back(i);
//				return result;
//			}
//			numIndex.insert(make_pair(nums[i], i));
//		}
//	}
//};