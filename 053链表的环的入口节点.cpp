/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if(!pHead)return nullptr;
        map<ListNode *,int>map;
        ListNode *cur=pHead;
        ListNode *res;
        while(cur)
        {
            if(map[cur]==2)
            {
                res=cur;
                break;
            }
            map[cur]++;
            cur=cur->next;
        }
        return res;
    }
   //根据快慢指针找环的入口；
     ListNode *Meet(ListNode *pHead)
 {
     if(!pHead||pHead->next==nullptr)
         return nullptr;
     ListNode *p1=pHead;//注意这里一定要从同一个点开始；
     ListNode *p2=pHead;
     while(p1&&p1->next)
     {
         p1=p1->next->next;
         p2=p2->next;
         if(p1==p2)
             return p1;
     }
     return nullptr;
 }
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if(!pHead||!pHead->next)return nullptr;//注意这里返回空；
        ListNode *cur=pHead;
        ListNode *meetNode=Meet(pHead);
        ListNode *p1=meetNode;
        ListNode *p2=pHead;
        while(p1!=p2)
        {
            p1=p1->next;
            p2=p2->next;
        }
        return p1;
    }
};
