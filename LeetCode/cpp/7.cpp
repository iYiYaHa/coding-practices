//#include<iostream>
//
//class Solution {
//public:
//	int reverse(int x);
//};
//
//int main()
//{
//	Solution solution;
//	int num = 0; 
//	std::cout << sizeof(int) << std::endl;
//	while (std::cin >> num) {
//		std::cout << solution.reverse(num)<<std::endl;
//	}
//
//	return 0;
//}
//
//int Solution::reverse(int x)
//{
//	int ans = 0;
//	int prev = 0;
//	while (x != 0) {
//		prev = ans;
//		ans = ans * 10 + (x % 10);
//		if (x > 0 && prev > ans / 10)
//			return 0;
//		if (x < 0 && prev < ans / 10)
//			return 0;
//		x /= 10;
//	}
//		
//	return x >= 0 ? ans : (-ans);
//}