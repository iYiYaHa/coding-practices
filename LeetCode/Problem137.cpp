#include<iostream>
#include<vector>
#include<algorithm>

class SolutionA {
	// Time Complexity: O(32n) = O(n)
public:
	int singleNumber(std::vector<int>& nums) {
		int ans = 0;
		for (int i = 0; i < 32; ++i) {// Traverse each bit
			int count = 0;// Recording the number of numbers whose ith bit is 1
			for (const int num : nums) {// Traverse every number and judge whether ith bit is 1
				count += (num >> i) & 1;
			}
			ans |= ((count % 3) << i);// Model 3 to filter all numbers appearing three times.
		}
		return ans;
	}
};
class SolutionB {
	// Time Complexity: O(nlogn)
	// Sort first
public:
	int singleNumber(std::vector<int>& nums) {
		std::sort(nums.begin(), nums.end());
		if (nums.size() == 0) return 0;
		for (int i = 0; i < nums.size() - 2; i++) {
			if (nums[i] != nums[i + 1] || nums[i] != nums[i + 2]) {
				return nums[i];
			}
			else {
				i += 2;
			}
		}
		return nums[nums.size() - 1];
	}
};

class SolutionC {
	//ref: https://leetcode.com/problems/single-number-ii/discuss/43296/An-General-Way-to-Handle-All-this-sort-of-questions.
public:
	int singleNumber(std::vector<int>& nums) {
		int a = 0, b = 0;
		for (const int &num : nums) {
			int ta = a;
			a = (num & b & ~a) | (a & ~b & ~num);
			b = (~ta & ~b & num) | (~ta & b & ~num);
			//std::cout<<"a:"<<a<<" b:"<<b<<std::endl;
		}
		return b;
	}
};
class SolutionD {
	//b = ~a & (b & ~c | ~b & c) = ~a & b ^ c
	//	Now that we've got a simplier representation of 'b', maybe we could represent 'a' easier using this newly caculated 'b', which we will denoted as 'b1'.

	//	a b b1 c a b
	//	1 0 0 0 1 0
	//	0 1 0 1 1 0

	//	we could see in both case b1 is 0, so a = ~b1 & (a ^ c), which is consistent with the most voted answer.
public:
	int singleNumber(std::vector<int>& nums) {
		int a = 0, b = 0;
		for (const int &num : nums) {
			b = ~a &(b^num);
			a = (~b)&(a^num);
		}
		return b;
	}
};

class SolutionE {
public:
	int singleNumber(std::vector<int>& nums) {
		int ones = 0, twos = 0, threes = 0;
		for (const int &num : nums) {
			// twos holds the num that appears twice
			twos |= ones & num;

			// ones holds the num that appears once
			ones ^= num;

			// threes holds the num that appears three times
			threes = ones & twos;

			// if num[i] appears three times
			// doing this will clear ones and twos
			ones &= ~threes;
			twos &= ~threes;
		}
		return ones;
	}
};

class SolutionF {

	//ref: https://leetcode.com/problems/single-number-ii/discuss/43302/Accepted-code-with-proper-Explaination.-Does-anyone-have-a-better-idea
public:
	// Let us take the example of {3, 3, 2, 3} to understand this
	int singleNumber(std::vector<int>& nums) {
		int ones = 0, twos = 0;
		int common_bit_mask;
		for (const int &num : nums) {
			/* The expression "one & arr[i]" gives the bits that are
		  there in both 'ones' and new element from arr[].  We
		  add these bits to 'twos' using bitwise OR

		  Value of 'twos' will be set as 0, 3, 3 and 1 after 1st,
		  2nd, 3rd and 4th iterations respectively */

			twos = twos | (ones&num);
			/* XOR the new bits with previous 'ones' to get all bits
		   appearing odd number of times

		   Value of 'ones' will be set as 3, 0, 2 and 3 after 1st,
		   2nd, 3rd and 4th iterations respectively */
			ones = ones ^ num;
			/* The common bits are those bits which appear third time
		  So these bits should not be there in both 'ones' and 'twos'.
		  common_bit_mask contains all these bits as 0, so that the bits can
		  be removed from 'ones' and 'twos'

		  Value of 'common_bit_mask' will be set as 00, 00, 01 and 10
		  after 1st, 2nd, 3rd and 4th iterations respectively */
			common_bit_mask = ~(ones&twos);
			/* Remove common bits (the bits that appear third time) from 'ones'

		   Value of 'ones' will be set as 3, 0, 0 and 2 after 1st,
		   2nd, 3rd and 4th iterations respectively */
			ones &= common_bit_mask;
			/* Remove common bits (the bits that appear third time) from 'twos'

		   Value of 'twos' will be set as 0, 3, 1 and 0 after 1st,
		   2nd, 3rd and 4th itearations respectively */
			twos &= common_bit_mask;
		}
		return ones;
	}
};

// SolutionG
// ref:https://leetcode.com/problems/single-number-ii/discuss/43322/My-O(n)-solution-without-using-bit-operation-and-extra-space
// based on quick sort.

class SolutionH {
	//ref:https://leetcode.com/problems/single-number-ii/discuss/43294/Challenge-me-thx
public:
	// Let us take the example of {3, 3, 2, 3} to understand this
	int singleNumber(std::vector<int>& nums) {
		/*
			This is a case of a finite state machine.
			States of machine- Total three (number appeared once, number appeared twice, number appeared thrice)
			Action - Incoming bit of one
			We will need two bits to keep track of the state. So lets take those states as 00, 01 and 10.
			The states will transition like 00 -> 01 -> 10 with every incoming bit.
			Now lets look at the individual bits.
			First bit - 0 -> 0 -> 1 -> back to 0
			Second bit - 0 -> 1 -> 0 -> back to 0
			Note that these bits are transitioning with every state change. Now we need to find a pattern of this change.

			For first bit it is sufficient to say that with every incoming 1 bit, its next state is its XOR with it with an exception-
			If second bit is set, the first bit becomes zero. So we come up with =>
			ones = ones ^ A[i];
			if (twos == 1) then ones = 0
			It condenses to (ones ^ A[i]) & ~twos;

			For second bit, it is sufficient to say that with every incoming 1 bit, its next state is its XOR with it with an exception-
			If the one's bit after the change above is set, then it will become zero too. So we come up with =>
			twos = twos ^ A[i];
			if (ones* == 1) then twos = 0
			It condenses to (twos ^ A[i]) & ~ones;
			 */
		int ones = 0, twos = 0;
		for (const int&num : nums) {

			// Accumulate the incoming number in ones provided twos is zero.
			// Twos will hold the number that has appeared twice.
			// If two becomes zero, it means the number has appeared the third time- Ones will hold that number now
			ones = (ones ^ num) & ~twos;

			// Wait for ones bits to be zero before you increment twos.
			// Ones will be zero when the number is received twice.
			// So when the number will be received twice, we will store that in twos.
			twos = (twos ^ num) & ~ones;
		}
		return ones;
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