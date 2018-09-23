////Solution One
///**
//* Definition for singly-linked list.
//* struct ListNode {
//*     int val;
//*     ListNode *next;
//*     ListNode(int x) : val(x), next(NULL) {}
//* };
//*/
//class Solution {
//public:
//	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//		int length1 = 0, length2 = 0;
//		ListNode * p = l1, *q = l2, *tail = nullptr;
//
//		//Compute the number of digits of the two numbers.
//		while (p != nullptr) {
//			++length1;
//			p = p->next;
//		}
//		while (q != nullptr) {
//			++length2;
//			q = q->next;
//		}
//
//		//p points at the longer one, q points at the shorter one.
//		p = l1;
//		q = l2;
//		int diff = length1 - length2;
//		if (length1 < length2) {
//			p = l2;
//			q = l1;
//			diff = length2 - length1;
//		}
//
//		int carry = 0;
//		while (p != nullptr && q != nullptr) {
//			int sum = (p->val + q->val + carry);
//			p->val = sum % 10;
//			carry = sum / 10;
//			tail = p;
//			p = p->next;
//			q = q->next;
//		}
//
//		while (diff > 0 && carry != 0) {
//			int sum = (p->val + carry);
//			p->val = sum % 10;
//			carry = sum / 10;
//			tail = p;
//			p = p->next;
//			--diff;
//		}
//		//skip the longer part of p
//
//		if (diff == 0 && carry != 0) {
//			ListNode * tmp = new ListNode(carry);
//			tail->next = tmp;
//		}
//
//		return length1 < length2 ? l2 : l1;
//	}
//};
//
//
////Solution Two
///**
//* Definition for singly-linked list.
//* struct ListNode {
//*     int val;
//*     ListNode *next;
//*     ListNode(int x) : val(x), next(NULL) {}
//* };
//*/
//class Solution {
//public:
//	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//		ListNode * p = l1, *q = l2, *tail1 = nullptr, *tail2 = nullptr;
//		int carry = 0;
//		while (p != nullptr && q != nullptr) {
//			int sum = p->val + q->val + carry;
//			p->val = sum % 10;
//			carry = sum / 10;
//			tail1 = p;
//			p = p->next;
//			tail2 = q;
//			q = q->next;
//		}
//
//		if (p == nullptr && q == nullptr) {//len(l1) == len(l2)
//			if (carry != 0) {
//				ListNode * tmp = new ListNode(carry);
//				tail1->next = tmp;
//			}
//			return l1;
//		}
//		else if (p == nullptr && q != nullptr) {//len(l1) < len(l2)
//			tail1->next = q;
//			while (q != nullptr) {
//				int sum = q->val + carry;
//				q->val = sum % 10;
//				carry = sum / 10;
//				tail2 = q;
//				q = q->next;
//			}
//			if (carry != 0) {
//				ListNode * tmp = new ListNode(carry);
//				tail2->next = tmp;
//			}
//			return l1;
//
//		}
//		else if (p != nullptr && q == nullptr) {//len(l1) > len(l2)
//			while (p != nullptr) {
//				int sum = p->val + carry;
//				p->val = sum % 10;
//				carry = sum / 10;
//				tail1 = p;
//				p = p->next;
//			}
//			if (carry != 0) {
//				ListNode * tmp = new ListNode(carry);
//				tail1->next = tmp;
//			}
//			return l1;
//		}
//	}
//};
//
////Solution Three
///**
//* Definition for singly-linked list.
//* struct ListNode {
//*     int val;
//*     ListNode *next;
//*     ListNode(int x) : val(x), next(NULL) {}
//* };
//*/
//class Solution {
//public:
//	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//		ListNode * head = new ListNode(0), *tail = nullptr, *p = l1, *q = l2;
//		int carry = 0;
//		while (p != nullptr || q != nullptr || carry) {
//			int x = p ? p->val : 0;
//			int y = q ? q->val : 0;
//			int sum = x + y + carry;
//			carry = sum / 10;
//			ListNode * tmp = new ListNode(sum % 10);
//			tail->next = tmp;
//			tail = tmp;
//			p = p ? p->next : p;
//			q = q ? q->next : q;
//		}
//		return head.next;
//	}
//};
