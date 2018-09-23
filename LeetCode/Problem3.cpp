//#include<string>
//#include<iostream>
//#include<vector>
//#include<unordered_map>
//#include<set>
//using namespace std;
//int lengthOfLongestSubstring(string s);
//bool uniqueStr(string s);
//int main()
//{
//	string haha;
//	while (std::cin >> haha)
//		std::cout << lengthOfLongestSubstring(haha) << std::endl;
//	return 0;
//}
//
//////Solution one (naive approach)
////int lengthOfLongestSubstring(string s)
////{
////	int maxlength = 0;
////	for (size_t i = 0; i < s.size(); ++i) {
////		for (size_t j = i; j < s.size(); ++j) {
////			if (uniqueStr(s.substr(i,j-i+1)))
////				maxlength = maxlength > (j - i + 1) ? maxlength : (j - i + 1);
////		}
////	}
////	return maxlength;
////}
////
////bool uniqueStr(string s)
////{
////	vector<bool> table(256, false);
////	std::cout << s << std::endl;
////	for (size_t i = 0; i < s.size();++i) {
////		if (table[s[i]] == true)
////			return false;
////		else
////			table[s[i]] = true;
////	}
////	return true;
////}
//
//////Solution Two
////int lengthOfLongestSubstring(string s)
////{
////	size_t i = 0, j = 0;
////	set<char> alphaSet;
////	int max = 0;
////	while (i < s.size() && j < s.size()) {
////		if (alphaSet.find(s[j]) == alphaSet.end()) {
////			max = max > j - i + 1 ? max : j - i + 1;
////			alphaSet.insert(s[j++]);
////		}
////		else
////			alphaSet.erase(s[i++]);
////	}
////	return max;
////}
//
//////Solution Three
//int lengthOfLongestSubstring(string s )
//{
//	int ans = 0;
//	unordered_map<char, int> table;
//	for (size_t i = 0, j = 0; j < s.size();table[s[j]] = j,++j) {
//		if (!(table.find(s[j]) == table.end()))//s[j] in table 
//			i = i > table[s[j]] ? i : table[s[j]] + 1;
//		ans = ans >= j - i + 1 ? ans : (j - i + 1);
//	}//tmmzuxt
//	return ans;
//}
//
////Solution Four O(n)
////int lengthOfLongestSubstring(string s) {
////	int alpha[256];
////	for (int i = 0; i < 256; ++i)
////		alpha[i] = -1;
////	int maxlength = 0, length = 0;
////	for (int i = 0; i < s.size(); ++i) {
////		int index = s[i];
////		if (alpha[index] == -1) {
////			alpha[index] = i;
////			++length;
////		}
////		else {
////			if (alpha[index] < (i - length)) {//index not in current substring
////				alpha[index] = i;
////				++length;
////			}
////			else {//index in current substring
////				if (length > maxlength)
////					maxlength = length;
////				length = i - alpha[index];
////				alpha[index] = i;
////			}
////		}
////	}
////	if (length > maxlength)
////		maxlength = length;
////	return maxlength;
////}