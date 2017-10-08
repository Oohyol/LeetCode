/*Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.*/

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
	ListNode* swapPairs(ListNode* head) {
		ListNode *dummy = new ListNode(0);
		dummy->next = head;
		ListNode *p = dummy;
		while (p->next&&p->next->next) {
			ListNode *node1 = p->next;
			ListNode *node2 = node1->next;
			ListNode *next = node2->next;
			node2->next = node1;
			node1->next = next;
			p->next = node2;
			p = node1;
		}
		ListNode *retNode = dummy->next;
		delete dummy;
		return retNode;
	}
};