/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
//中序遍历的思路 先从左子树中找 第k个节点；
//然后从中路去找；再去右子树中去找；
class Solution {
private:
    int count=0;
public:
    
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(!pRoot||k<0)return nullptr;
        TreeNode *res=KthNode(pRoot->left,k);
        if(res)return res;
        if(++count==k)return pRoot;
        res=KthNode(pRoot->right,k);
        if(res)
            return res;
        return nullptr;
    }

    
};
