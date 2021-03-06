/*Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.*/

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
	ListNode* partition(ListNode* head, int x) {

		ListNode* small = new ListNode(0);
		ListNode* big = new ListNode(0);
		ListNode *left = small, *right = big;
		while (head != NULL)
		{
			if (head->val<x)
			{
				small->next = head;
				small = head;
			}
			else
			{
				big->next = head;
				big = head;
			}
			head = head->next;
		}
		big->next = NULL;
		small->next = right->next;
		return left->next;
	}
};