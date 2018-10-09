/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
//思路就是按照中序遍历的方式去解决这个问题；
//中序遍历的方式去改变指针的指向；
//先找到头结点把；也就是最左
class Solution {
public:
    void helper(TreeNode *cur,TreeNode * &pre)//中序遍历的方式去改变指针的指向；第二个参数必须为引用；
    {
        if(cur==nullptr)return ;
        helper(cur->left,pre);
        cur->left=pre;
        if(pre) pre->right=cur;
        pre=cur;
        helper(cur->right,pre);
    }
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(!pRootOfTree)return nullptr;
        TreeNode *pre=nullptr;
        helper(pRootOfTree,pre);
        TreeNode *head=pRootOfTree;
        while(head->left)
            head=head->left;
        return head;
            
    }
};
