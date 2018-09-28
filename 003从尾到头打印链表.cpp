/*
题目描述
输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。
*/
/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head)
    {
        vector<int>result;
        if(!head)return result;
        stack<int>stk;
        while(head)
        {
            stk.push(head->val);
            head=head->next;
        }
        while(stk.size())
        {
            result.push_back(stk.top());
            stk.pop();
        }
        return result;
    }
   
};
