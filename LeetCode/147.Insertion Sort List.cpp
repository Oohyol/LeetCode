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
	ListNode* insertionSortList(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;
		ListNode *dummy = new ListNode(0);
		dummy->next = head;
		ListNode *p = head;
		while (p->next != NULL)
		{
			if (p->val <= p->next->val)
				p = p->next;
			else
			{
				ListNode *q = dummy;
				ListNode *temp = p->next;
				p->next = p->next->next;
				while (q->next->val<temp->val)
					q = q->next;
				temp->next = q->next;
				q->next = temp;
			}
		}
		return dummy->next;
	}
};