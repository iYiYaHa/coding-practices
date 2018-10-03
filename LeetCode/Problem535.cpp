////Problem : Encode and Decode TinyURL
////
////Problem Description:
////  TinyURL is a URL shortening service where you enter a URL such 
////  as https://leetcode.com/problems/design-tinyurl and it returns 
////  a short URL such as http://tinyurl.com/4e9iAk.
////
////  Design the encode and decode methods for the TinyURL service.
////  There is no restriction on how your encode / decode algorithm 
////  should work.You just need to ensure that a URL can be encoded 
////  to a tiny URL and the tiny URL can be decoded to the original URL.
//
//#include <iostream>
//#include <vector>
//#include <string>
//#include <set>
//#include <unordered_map>
//#define max(a,b) ((a)>(b)?(a):(b))
//
//class Solution {
//public:
//	// Encodes a URL to a shortened URL.
//	std::string encode(std::string longUrl) {
//		int id = _idUrlMap.size() + 12699;// 12699 is just a random number, to make sure the first addresses won't start with zeros.
//		_idUrlMap.insert(std::make_pair(id, longUrl));
//		std::string encodeUrl;
//		while (id != 0 || encodeUrl.length() != 8) {
//			encodeUrl += _dict[id%_dict.size()];
//			id /= _dict.size();
//		}
//		return _baseUrl + encodeUrl;
//	}
//
//	// Decodes a shortened URL to its original URL.
//	std::string decode(std::string shortUrl) {
//		std::string decodeUrl;
//		int id = 0;
//		for (int i = shortUrl.length() - 1; i >= _baseUrl.length(); --i) {
//			int pos = getIndInDict(shortUrl[i]);
//			id = id * _dict.size() + pos;
//		}
//		decodeUrl = _idUrlMap[id];
//		return decodeUrl;
//	}
//
//private:
//	int getIndInDict(char ch) {
//		int ind = 0;
//		for (int i = 0; i < _dict.size(); ++i) {
//			if (_dict[i] == ch) {
//				ind = i;
//				break;
//			}
//		}
//		return ind;
//	}
//	std::unordered_map<int, std::string> _idUrlMap;
//	const std::string _dict = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
//	const std::string _baseUrl = "https://tinyurl.com/";
//};
//
//// Your Solution object will be instantiated and called as such:
//// Solution solution;
//// solution.decode(solution.encode(url));
//
//int main() {
//	Solution solution;
//	std::cin.get();
//	return 0;
//}