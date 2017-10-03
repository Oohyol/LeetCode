/*翻译
给你两个表示两个非负数字的链表。数字以相反的顺序存储，其节点包含单个数字。将这两个数字相加并将其作为一个链表返回。

输入: (2 -> 4 -> 3) + (5 -> 6 -> 4)
输出: 7 -> 0 -> 8

原文
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/


class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *c1 = l1;
		ListNode *c2 = l2;
		ListNode *sentinel = new ListNode(0);
		ListNode *d = sentinel;
		int sum = 0;
		while (c1 != nullptr || c2 != nullptr) {
			sum /= 10;
			if (c1 != nullptr) {
				sum += c1->val;
				c1 = c1->next;
			}
			if (c2 != nullptr) {
				sum += c2->val;
				c2 = c2->next;
			}
			d->next = new ListNode(sum % 10);
			d = d->next;
		}
		if (sum / 10 == 1)
			d->next = new ListNode(1);
		return sentinel->next;


	}
};