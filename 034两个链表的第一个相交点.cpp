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
//一、按照长度求解；
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) 
    {
        if(!pHead1||!pHead2)
            return nullptr;
        ListNode *l1=pHead1;
        ListNode *l2=pHead2;
        int len1=0,len2=0;
        while(l1)
        {
            len1++;
            l1=l1->next;
        }
        while(l2)
        {
            len2++;
            l2=l2->next;
        }
        ListNode *p1=pHead1;
        ListNode *p2=pHead2;
        if(len1<len2)
        {
           p1=pHead2;
           p2=pHead1;
        }
        int dis=len1-len2;
        while(dis-->0)
            p1=p1->next;
        while(p1&&p2)
        {
            if(p1==p2)
                break;
            p1=p1->next;
            p2=p2->next;
        }
        return p1;
    }
    //用map的方法；
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) 
    {
        map<ListNode *,int>dict;
        ListNode *p1=pHead1;
        ListNode *p2=pHead2;
        while(p1)
        {
            dict[p1]++;
            p1=p1->next;
        }
        while(p2)
        {
            if(dict[p2]==1)
                break;
            p2=p2->next;
        }
        return p2;
    }
    //反复判断；遇到终点就重新赋值为另一个链表；
      ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) 
    {
        ListNode *p1=pHead1;
        ListNode *p2=pHead2;
        while(p1!=p2)
        {
            p1= (p1?p1->next:pHead2);
            p2= (p2?p2->next:pHead1);
        }
        return p1;
    }
};
