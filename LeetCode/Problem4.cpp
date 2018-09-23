//#include<iostream>
//#include<vector>
//using namespace std;
//class Solution {
//public:
//	////Solution One
//	//double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//	//	int n = nums1.size(), m = nums2.size();
//	//	bool isOdd = true;
//	//	int ansIndex = 0;
//	//	int last1st = 0, last2nd = 0;
//	//	if ((n + m) % 2 == 0) {
//	//		isOdd = false;
//	//		ansIndex = (n + m) / 2 + 1;
//	//	}
//	//	else {
//	//		isOdd = true;
//	//		ansIndex = (n + m + 1) / 2 ;
//	//	}
//	//	size_t i = 0, j = 0;
//	//	while ((i + j ) < ansIndex) {
//	//		last2nd = last1st;
//	//		if (i < n && j < m) {
//	//			if (nums1[i] < nums2[j]) {
//	//				last1st = nums1[i];
//	//				++i;
//	//			}
//	//			else {
//	//				last1st = nums2[j];
//	//				++j;
//	//			}
//	//		}
//	//		else if (i >= n) {
//	//			last1st = nums2[j];
//	//			++j;
//	//		}
//	//		else {
//	//			last1st = nums1[i];
//	//			++i;
//	//		}
//	//	}
//
//	//	if (isOdd) {
//	//		return last1st;
//	//	}
//	//	else { 
//	//		return (last1st + last2nd) / 2.0;
//	//	}
//	//}
//	//Solution Two
//
//	double findMedian(vector<int>& A, vector<int>& B) {
//		int m = A.size(), n = B.size();
//		int imin = 0, imax = m;//why not m - 1?
//		int halfLen = (m + n + 1) / 2;
//		while (imin <= imax) {
//			int i = (imin + imax) / 2;
//			int j = halfLen - i;
//
//			if ((i == 0 || j == n || A[i - 1] <= B[j]) && (j == 0 || i == m || B[j - 1] <= A[i])) {
//				int maxLeft = 0;
//				if (j == 0) { maxLeft = A[i - 1]; }
//				else if (i == 0) { maxLeft = B[j - 1]; }
//				else { maxLeft = A[i - 1] > B[j - 1] ? A[i - 1] : B[j - 1]; }
//				if ((m + n) % 2 != 0) return maxLeft;
//
//				int minRight = 0;
//				if (j == n) { minRight = A[i]; }
//				else if (i == m) { minRight = B[j]; }
//				else { minRight = A[i] < B[j] ? A[i] : B[j]; }
//
//				return (maxLeft + minRight) / 2.0;
//			}
//			else if (i < m && A[i - 1] > B[j]) {
//				imax = i - 1;
//			}
//			else {
//				imin = i + 1;
//			}
//		}
//		return 0.0;
//	}
//
//	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//		if (nums1.size() == 0 && nums2.size() == 0)
//			return 0.0;
//		if (nums1.size() > nums2.size())
//			return findMedian(nums2, nums1);
//		return findMedian(nums1, nums2);
//	}
//};
//
//int main()
//{
//	Solution solution;
//	std::vector<int> nums1;
//	std::vector<int> nums2;
//	size_t m = 0, n = 0;
//	while (std::cin >> m) {
//		nums1.clear();
//		nums2.clear();
//		int tmp;
//		for (size_t i = 0; i < m; ++i) {
//			std::cin >> tmp;
//			nums1.push_back(tmp);
//		}
//		std::cin >> n;
//		for (size_t i = 0; i < n; ++i) {
//			std::cin >> tmp;
//			nums2.push_back(tmp);
//		}
//		std::cout << solution.findMedianSortedArrays(nums1, nums2) << std::endl;
//	}
//	return 0;
//}
