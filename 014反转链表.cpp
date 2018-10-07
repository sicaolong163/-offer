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
    ListNode* ReverseList(ListNode* pHead) 
    {
        if(pHead==nullptr)return nullptr;
        ListNode *pre=nullptr;
        ListNode *cur=pHead;
        while(cur)
        {
            ListNode *pNext=cur->next;
            cur->next=pre;
            pre=cur;
            cur=pNext;
        }
        return pre;
    }
};
