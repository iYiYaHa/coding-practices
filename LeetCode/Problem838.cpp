//Problem : Push Dominoes
//
//Problem Description:
// There are N dominoes in a line, and we place each domino vertically upright.
// 
// In the beginning, we simultaneously push some of the dominoes either to the left or to the right.
// 
// After each second, each domino that is falling to the left pushes the adjacent domino on the left.
// 
// Similarly, the dominoes falling to the right push their adjacent dominoes standing on the right.
// 
// When a vertical domino has dominoes falling on it from both sides, it stays still due to the balance 
// of the forces.
// 
// For the purposes of this question, we will consider that a falling domino expends no additional force 
// to a falling or already fallen domino.
// 
// Given a string "S" representing the initial state.S[i] = 'L', if the i - th domino has been pushed to 
// the left; S[i] = 'R', if the i - th domino has been pushed to the right; S[i] = '.', if the i - th domino 
// has not been pushed.
// 
// Return a string representing the final state.
//  
//  
//  Example 1:
//  
//  Input: ".L.R...LR..L.."
//  Output : "LL.RR.LLRRLL.."
//  
//  Example 2 :
//  
//  Input : "RR.L"
//  Output : "RR.L"
//  Explanation : The first domino expends no additional force on the second domino.

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class SolutionA {
public:
	string pushDominoes(string dominoes) {
		int n = dominoes.size();
		std::vector<int> res(n);
		int force = 0;
		//from left to right
		for (int i = 0; i < n; ++i)
		{
			if (dominoes[i] == 'R')
				force = n;
			else if (dominoes[i] == 'L')
				force = 0;
			res[i] -= (force > 0 ? force : 0);
			--force;
		}
		force = 0;
		//from right to left
		for (int i = n - 1; i >= 0; --i)
		{
			if (dominoes[i] == 'L')
				force = n;
			else if (dominoes[i] == 'R')
				force = 0;
			res[i] += (force > 0 ? force : 0);
			--force;
		}
		std::string ans;
		for (int i = 0; i < n; ++i)
			ans += (res[i] > 0 ? 'L' : (res[i] < 0 ? 'R' : '.'));
		return ans;
	}
};

class SolutionB {
public:
	string pushDominoes(string dominoes) {
		std::string processed_dominos = "L";
		processed_dominos += dominoes;
		processed_dominos += 'R';

		for (int left = 0, right = 1; right < processed_dominos.size(); ++right)
		{
			std::string::value_type &lval = processed_dominos[left];
			std::string::value_type &rval = processed_dominos[right];
			if (rval == 'R')
			{
				if (lval == 'R')
				{
					// R...R
					while (left != right) processed_dominos[++left] = 'R';
				}
				else if (lval == 'L')
				{
					// L...R do nothing
					left = right;
				}
			}
			else if (rval == 'L')
			{
				if (lval == 'L')
				{
					//L...L
					while (left != right) processed_dominos[++left] = 'L';
				}
				else if (lval == 'R')
				{
					int tmp_left = left + 1;
					int tmp_right = right - 1;
					while (tmp_left < tmp_right)
					{
						processed_dominos[tmp_left++] = 'R';
						processed_dominos[tmp_right--] = 'L';
					}
					if (tmp_left == tmp_right)processed_dominos[tmp_left] = '.';
					left = right;
				}

			}
		}
		return processed_dominos.substr(1, dominoes.size());
	}
};
int main() {
	std::vector<std::string> testCase = { "RR.L",".L.R...LR..L.." };
	std::vector<std::string> testAns = { "RR.L","LL.RR.LLRRLL.." };
	for (int i = 0; i < testCase.size(); ++i) {
		bool result = SolutionA().pushDominoes(testCase[i])== testAns[i];
		if (result)
			std::cout << "Test case " << i + 1 << " passed." << std::endl;
		else
			std::cout << "Test case " << i + 1 << " failed." << std::endl;
	}
	std::cin.get();
	return 0;
}