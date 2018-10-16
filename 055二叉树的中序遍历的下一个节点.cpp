/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(!pNode )return nullptr;
        TreeLinkNode*cur=pNode ;
        if(cur->right)
        {
            TreeLinkNode *node=cur->right;
            while(node->left)
                node=node->left;
            return node;
        }
        while(cur->next)
        {
            if(cur->next->left==cur)
                return cur->next;
            cur=cur->next;
        }
        return nullptr;
    }
};
