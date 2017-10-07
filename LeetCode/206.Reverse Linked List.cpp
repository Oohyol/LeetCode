/*Reverse a singly linked list.*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

class Solution      //非递归
{   
public:
	ListNode* reverseList(ListNode* head) {
		ListNode *pre = NULL;
		ListNode *cur = head;
		while (cur != NULL)
		{
			ListNode*next = cur->next;
			cur->next = pre;
			pre = cur;
			cur = next;
		}
		return pre;
	}
};


class Solution   //递归
{ 
public:
	ListNode* reverseList(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;
		ListNode *pnext = head->next;
		ListNode *phead = reverseList(pnext);
		pnext->next = head;
		head->next = NULL;
		return phead;
	}
};