/*Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.*/

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
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode *dummy = new ListNode(0);
		dummy->next = head;
		ListNode *p = dummy;
		ListNode *q = dummy;
		for (int i = 0;i<n + 1;i++)
		{
			assert(q);
			q = q->next;
		}
		while (q)
		{
			p = p->next;
			q = q->next;
		}
		ListNode *delNode = p->next;
		p->next = delNode->next;
		delete delNode;
		return dummy->next;

	}
};



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
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		int count = 0;
		ListNode *phead = head;
		while (phead)
		{
			count++;
			phead = phead->next;
		}
		int index = count - n;
		ListNode *p = head;
		if (index == 0)
		{
			head = head->next;
		}
		else
		{
			while (--index)
			{
				p = p->next;
			}
			p->next = p->next->next;
		}
		return head;
	}
};