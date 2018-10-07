/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* CloneNode(RandomListNode*head)
    {
        RandomListNode *cur=head;
        while(cur)
        {
            RandomListNode *node=new RandomListNode(cur->label);
            node->next=cur->next;
            node->random=nullptr;
            cur->next=node;
            cur=node->next;
        }
        return head;
    }
    RandomListNode*RandomNode(RandomListNode* head)
    {
        RandomListNode*cur=head;
        while(cur)
        {
            if(cur->random)
                cur->next->random=cur->random->next;
            cur=cur->next->next;
        }
        return head;
    }
    RandomListNode*deleteNode( RandomListNode* head)
    {
        RandomListNode* cur=head;
        RandomListNode*cloneHead=nullptr;
        RandomListNode*clone=nullptr;
        if(cur)
        {
            cloneHead=clone=head->next;
            cur->next=clone->next;
            cur=cur->next;
        }
        while(cur)
        {
            clone->next=cur->next;
            clone=clone->next;
            cur->next=clone->next;
            cur=cur->next;
        }
        return cloneHead;
        
    }
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(!pHead)return nullptr;
       pHead= CloneNode(pHead);
        pHead=RandomNode(pHead);
        pHead=deleteNode(pHead);
        return pHead;
    }
};
