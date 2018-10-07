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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) 
    {
        if(pListHead==nullptr||k==0)return nullptr;
        ListNode *fast=pListHead;
        while(fast&&k>0)
        {
            fast=fast->next;
            k--;
        }
        if(k>0)
            return nullptr;
        ListNode *slow=pListHead ;
        while(fast)
        {
            fast=fast->next;
            slow=slow->next;
        }
        return slow;
        
    }
};
