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
    /*ListNode* deleteDuplication(ListNode* pHead)
    {
        if(!pHead)return nullptr;
        ListNode *pre=nullptr;
        ListNode *cur=pHead;
       if(cur->next&&cur->next->val==cur->val)
       {
           ListNode *node=cur->next;
           while(node&&node->val==cur->val)
               node=node->next;
           return deleteDuplication(node);//从第一个不相等的开始递归运行；
       }
        else
            cur->next=deleteDuplication(cur->next);
        return pHead;
    }
    */
    //思路二 设置一个 pre来记录不重复的；
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(!pHead)return nullptr;
        ListNode *dummy=new ListNode(0);
        dummy->next=pHead;
        ListNode *cur=pHead;
        ListNode *pre=dummy;
        while(cur&&cur->next)
        {
            if(cur->val==cur->next->val)
            {
                int val=cur->val;
                while(cur&&cur->val==val)
                {
                    cur=cur->next;
                }
                pre->next=cur;
            }
            else
            {
                pre=cur;
                cur=cur->next;
            }
        }
        return dummy->next;
    }

};
