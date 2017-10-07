/*Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.*/

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
	ListNode* deleteDuplicates(ListNode* head) {

		if (head == NULL || head->next == NULL)
			return head;

		ListNode *phead = head;
		ListNode *pcur = head;
		ListNode *pnext = head->next;
		while (pnext != NULL)
		{
			if (pnext->val != pcur->val)
			{
				pcur = pcur->next;
				pnext = pnext->next;
			}
			else
			{
				pcur->next = pnext->next;
				pnext = pnext->next;
			}
		}
		return phead;
	}
};