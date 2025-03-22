////Determine whether an integer is a palindrome. Do this without extra space.
//
//#include<iostream>
//
//class Solution {
//public:
//	//bool isPalindrome(int x) {
//	//	if (x == 0)
//	//		return true;
//	//	if (x == INT_MAX || x == INT_MIN)
//	//		return false;
//	//	//When handling the problems relevant to numbers, note that the problem of overflow.
//	//	if (x < 0)
//	//		return false;
//	//	long pow = 1;
//	//	while (x / pow != 0)
//	//		pow *= 10;
//	//	pow /= 10;
//
//	//	while (x % 10 == x / pow) {
//	//		x %= pow;
//	//		x /= 10;
//	//		pow /= 100;
//	//		if (pow == 0)
//	//			break;
//	//	}
//	//	return pow == 0;
//	//}
//	bool isPalindrome(int x) {
//		if (x < 0 || (x % 10 == 0 && x != 0))
//			return false;
//		int reversed = 0;
//		while (x > reversed) {
//			reversed = reversed * 10 + x % 10;
//			x /= 10;
//		}
//
//		return x == reversed || x == reversed / 10;//odd or even
//	}
//};
//
//int main()
//{
//	int num = 0;
//	Solution solution;
//	while(std::cin>>num){
//		std::cout << num;
//		std::cout << (solution.isPalindrome(num) ? "true" : "false") << std::endl;
//	}
//	return 0;
//}