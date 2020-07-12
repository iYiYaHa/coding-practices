////Given a non negative integer number num.For every numbers i in the range 0 ¡Ü i ¡Ü num calculate the number of 1's in their binary representation and return them as an array.
////
////Example:
////For num = 5 you should return[0, 1, 1, 2, 1, 2].
////
////Follow up :
////
////It is very easy to come up with a solution with run time O(n * sizeof(integer)).But can you do it in linear time O(n) / possibly in a single pass ?
////Space complexity should be O(n).
////Can you do it like a boss ? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.

//#include<vector>
//#include<iostream>
//
//class Solution {
//private:
//	int countBitsForNum(int num) {
//		int count = 0;
//		while (num != 0) {
//			count = ((num & 1) != 0) ? count + 1 : count;
//			num >>= 1;
//		}
//		return count;
//	}
//public:
//	//std::vector<int> countBits(int num) {
//	//	std::vector<int> answer;
//	//	for (int i = 0; i <= num; ++i) {
//	//		answer.push_back(countBitsForNum(i));
//	//	}
//	//	return answer;
//	//}
//	
//	//std::vector<int> countBits(int num) {
//	//	std::vector<int> answer(num+1,0);
//	//	for (int i = 0; i <= num/2; ++i) {
//	//		int front = i << 1;
//	//		int back = (i << 1) + 1;
//	//			answer[front] = answer[i];
//	//		if (back<answer.size())
//	//			answer[back] = answer[i] + 1;
//	//	}
//	//	return answer;
//	//}
//	std::vector<int> countBits(int num) {
//		std::vector<int> answer(num + 1, 0);
//		for (int i = 1; i <= num ; ++i) {
//			answer[i] = answer[i&(i - 1)] + 1;
//		}
//		return answer;
//	}
//};
//int main()
//{
//	int num = 0;
//	Solution solution;
//	while (std::cin >> num) {
//		std::vector<int> answer = solution.countBits(num);
//		std::cout << answer.size();
//		std::cout << "[";
//		for (const auto &i : answer) {
//			std::cout << i << ",";
//		}
//		std::cout << "]" << std::endl;
//	}
//	std::cin.get();
//	return 0;
//}