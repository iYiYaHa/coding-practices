////Problem : Find and Replace Pattern
////
////Problem Description:
////  You have a list of words and a pattern, and you want to know which words in words matches the pattern.
////  
////  A word matches the pattern if there exists a permutation of letters p so that after replacing every 
////  letter x in the pattern with p(x), we get the desired word.
////  
////  (Recall that a permutation of letters is a bijection from letters to letters : every letter maps to 
////  another letter, and no two letters map to the same letter.)
////  
////  Return a list of the words in words that match the given pattern.
////  
////  You may return the answer in any order.
////  
////  
////  Example1:
////  Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
////  Output: ["mee", "aqq"]
////  Explanation : "mee" matches the pattern because there is a permutation{ a->m, b->e, ... }.
////				  "ccc" does not match the pattern because{ a->c, b->c, ... } is not a permutation,
////				  since a and b map to the same letter.
//
////  Note:
//// 
////  1. 1 <= words.length <= 50
////  2. 1 <= pattern.length = words[i].length <= 20
//
//
//#include <iostream>
//#include <vector>
//#include <string>
//
//class Solution {
//public:
//	std::vector<std::string> findAndReplacePattern(std::vector<std::string>& words, std::string pattern) {
//		std::vector<std::string> res;
//		for (const auto &word : words) {
//			if (word.size() != pattern.size())
//				continue;
//			std::vector<char> wordToPattern(26, '\0');
//			std::vector<char> patternToWord(26, '\0');
//			bool flag = true;
//			for (int i = 0; i < word.size(); ++i) {
//				if (wordToPattern[word[i] - 'a'] != 0 && wordToPattern[word[i] - 'a'] != pattern[i]) {
//					flag = false;
//					break;
//				}
//				wordToPattern[word[i] - 'a'] = pattern[i];
//				if (patternToWord[pattern[i] - 'a'] != 0 && patternToWord[pattern[i] - 'a'] != word[i]) {
//					flag = false;
//					break;
//				}
//				patternToWord[pattern[i] - 'a'] = word[i];
//			}
//			if (flag == true)
//				res.push_back(word);
//		}
//		return res;
//	}
//};
//int main() {
//	Solution solution;
//	std::vector<std::pair<std::vector<std::string>, std::string>> testCase = { {{"abc","deq","mee","aqq","dkd","ccc"},"cdd" } };
//	std::vector<std::vector<std::string>> testAns = { {"mee","aqq"} };
//	for (int i = 0; i < testCase.size(); ++i) {
//		bool result = solution.findAndReplacePattern(testCase[i].first, testCase[i].second) == testAns[i];
//		if (result)
//			std::cout << "Test case " << i + 1 << " passed." << std::endl;
//		else
//			std::cout << "Test case " << i + 1 << " failed." << std::endl;
//	}
//	std::cin.get();
//	return 0;
//}