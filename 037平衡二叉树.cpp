class Solution {
public:
//思路一：用二叉树的深度和递归的方法 但是可能存在重复遍历的情况；
    int depth(TreeNode *root)
    {
        if(!root)return 0;
        return max(depth(root->left),depth(root->right))+1;
    }
    bool IsBalanced_Solution(TreeNode* pRoot) 
    {
        if(!pRoot)return true;
        int left=depth(pRoot->left);
        int right=depth(pRoot->right);
        int dis=left-right;
        if(dis>=-1&&dis<=1)
            return IsBalanced_Solution(pRoot->left)&&IsBalanced_Solution(pRoot->right);
        return false;
            
    }
    //思路二、只遍历一次的方法：
    
      bool helper(TreeNode *root,int &depth)
    {
        if(!root)return true;
        int left=0,right=0;
        if(helper(root->left,left)&&helper(root->right,right))
        {
            depth=1+max(left,right);
            int dis=left-right;
            if(dis<=1&&dis>=-1)
                return true;
            return false;
        }
        return false;
    }
    bool IsBalanced_Solution(TreeNode* pRoot)
    {
        if(!pRoot)return true;
        int depth=0;
        return helper(pRoot,depth);
    }
};
