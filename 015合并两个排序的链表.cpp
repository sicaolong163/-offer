/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1==nullptr)
            return pHead2;
        if(pHead2==nullptr)
            return  pHead1;
        ListNode *p1=pHead1;
        ListNode *p2=pHead2;
        ListNode *dummy=new ListNode (0);
        ListNode *p3=dummy;
        if(p1->val>p2->val)
        {
            p3->next=p2;
            p3->next->next=Merge(p1,p2->next);
        }
        else
        {
            p3->next=p1;
            p3->next->next=Merge(p1->next,p2);
        }
        return dummy->next;
    }
};
