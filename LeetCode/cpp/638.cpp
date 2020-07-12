////Problem : Shopping Offers
////
////Problem Description:
////  In LeetCode Store, there are some kinds of items to sell. Each item has a price.
////  
////  However, there are some special offers, and a special offer consists of one or 
////  more different kinds of items with a sale price.
////  
////  You are given the each item's price, a set of special offers, and the number we 
////  need to buy for each item. The job is to output the lowest price you have to pay 
////  for exactly certain items as given, where you could make optimal use of the special 
////  offers.
////  
////  Each special offer is represented in the form of an array, the last number represents 
////  the price you need to pay for this special offer, other numbers represents how many 
////  specific items you could get if you buy this offer.
////  
////  You could use any of special offers as many times as you want.
//
////  Example 1:
////  Input: [2,5], [[3,0,5],[1,2,10]], [3,2]
////  Output: 14
////  Explanation :
////		There are two kinds of items, A and B.Their prices are $2 and $5 respectively.
////		In special offer 1, you can pay $5 for 3A and 0B
////		In special offer 2, you can pay $10 for 1A and 2B.
////		You need to buy 3A and 2B, so you may pay $10 for 1A and 2B(special offer #2), and $4 for 2A.	
////  
////  Example 2:
////  Input: [2,3,4], [[1,1,0,4],[2,2,1,9]], [1,2,1]
////  Output: 11
////  Explanation :
////		The price of A is $2, and $3 for B, $4 for C.
////		You may pay $4 for 1A and 1B, and $9 for 2A, 2B and 1C.
////		You need to buy 1A, 2B and 1C, so you may pay $4 for 1A and 1B(special offer #1), and $3 for 1B, $4 for 1C.
////	 You cannot add more items, though only $9 for 2A, 2B and 1C.
////  
////  Note :
////  1. There are at most 6 kinds of items, 100 special offers.
////  2. For each item, you need to buy at most 6 of them.
////  3. You are not allowed to buy more items than you want, even if that would lower the overall price.
//
//#include <iostream>
//#include <string>
//#include <vector>
//#include <cassert>
//#include <algorithm>
//
//class Solution {
//
//public:
//	int shoppingOffers(std::vector<int>& price, std::vector<std::vector<int>>& special, std::vector<int>& needs) {
//		int sum = costDFS(price, special, needs);
//		return sum;
//	}
//private:
//
//	int costDFS(const std::vector<int>& price, const std::vector<std::vector<int>>& special, std::vector<int>& needs) {
//		bool noAvailableFlag = true;
//		int min_sum = 0;
//
//		int sum = 0;
//		for (int i = 0; i < price.size(); ++i) {
//			sum += price[i] * needs[i];
//		}
//		min_sum = sum;
//		for (int i = 0; i < special.size(); ++i) {
//			if (!isOfferAvailable(special[i], needs))
//				continue;
//			std::vector<int> new_needs = needs;
//			for (int j = 0; j < special[i].size() - 1; ++j) {
//				new_needs[j] = needs[j] - special[i][j];
//			}
//			min_sum = std::min(min_sum, special[i][special[i].size() - 1] + costDFS(price, special, new_needs));
//		}
//		return min_sum;
//	}
//	bool isOfferAvailable(const std::vector<int> &offer, const std::vector<int> &needs) {
//		if (offer.size() - 1 != needs.size()) {
//			return false;
//		}
//		for (int i = 0; i < offer.size() - 1; ++i) {
//			if (offer[i] > needs[i])
//				return false;
//		}
//		return true;
//	}
//};
//
//int main() {
//	std::vector<int> testCasePrice = { 0, 0, 0 };
//	std::vector<std::vector<int>> testCaseSpecial = { {1,1,0,4},{2,2,1,9} };
//	std::vector<int> testCaseNeeds = { 1, 1, 1 };
//	int testAns = 0;
//	/////////////////////////////////////////////////////////////////////////
//	//std::vector<int> testCasePrice = { 2,3,4 };
//	//std::vector<std::vector<int>> testCaseSpecial = { {1,1,0,4},{2,2,1,9},{2,2,1,9} };
//	//std::vector<int> testCaseNeeds = { 1,2,1 };
//	//int testAns = 11;
//	/////////////////////////////////////////////////////////////////////////
//	//	std::vector<int> testCasePrice = { 2,5 };
//	//std::vector<std::vector<int>> testCaseSpecial = { {3,0,5},{1,2,10} };
//	//std::vector<int> testCaseNeeds = { 3,2 };
//	//int testAns = 14;
//	/////////////////////////////////////////////////////////////////////////
//	bool res = Solution().shoppingOffers(testCasePrice, testCaseSpecial, testCaseNeeds) == testAns;
//	if (res) {
//		std::cout << "Test case passed.\n";
//	}
//	else {
//		std::cout << "Test case failed.\n";
//
//	}
//	std::cin.get();
//	return 0;
//}