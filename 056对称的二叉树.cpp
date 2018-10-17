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
class Solution {
public:
    bool helper(TreeNode*root1,TreeNode*root2)
    {
        if(!root1&&root2)return false;
        if(root1&&!root2)return false;//这里使用或运算出错；因为或运算包含三种情况
        if(!root1&&!root2)return true;
        if(root1->val!=root2->val)return false;
        
        return helper(root1->left,root2->right)&&helper(root1->right,root2->left);
    }
    bool isSymmetrical(TreeNode* pRoot)
    {
        if(!pRoot)return true;
        return helper(pRoot,pRoot);
    }

};
