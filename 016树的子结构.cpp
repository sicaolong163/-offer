/*
 题目描述
输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
*/
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    bool helper(TreeNode*root1,TreeNode*root2)
    {
        if(root2==nullptr)return true;
        if(root1==nullptr)return false;
        if(root1->val==root2->val)
            return helper(root1->left,root2->left)&&helper(root1->right,root2->right);
        return false;
    }
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(pRoot1==nullptr||pRoot2==nullptr)return false;
        return helper(pRoot1,pRoot2)||HasSubtree(pRoot1->left,pRoot2)||HasSubtree(pRoot1->right,pRoot2);
    }
};
