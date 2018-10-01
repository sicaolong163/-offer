/*
题目描述
  输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
  假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
  例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，
  则重建二叉树并返回。
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

    class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> in)
    {
        int length=pre.size();
        if(length==0)
            return nullptr;
        TreeNode* pRoot=new TreeNode(pre[0]);//创建根节点并进行初始化；必须初始化哟
        //pRoot->val=pre[0];
        pRoot->left=pRoot->right=nullptr;
        //此时只有一个结点
        if(pre[0]==pre[length-1])
        {
          if(pre[0]==in[0]&&in[0]==in[length-1])
              return  pRoot;
            else
                return nullptr;
        }
         
        //从中序遍历中找到根节点位置，并记录下来 pos_root_of_in;
        int pos_root_of_in=0;
        while(in[pos_root_of_in]!=pre[0])
            ++pos_root_of_in;
         
        vector<int >pre_left,pre_right,in_left,in_right;//左右子树的前序遍历数列与中序遍历数列；
        //左子树的确定（前序的范围:前序从第一位，到pos_root-of-in位）；
        for(int i=0;i<pos_root_of_in;++i)
        {
             in_left.push_back(in[i]);
            pre_left.push_back(pre[i+1]);
        
        }
        //右子树的确定（范围从根节点的下一位到终点）
        for(int i=pos_root_of_in+1;i<length;i++)
        {
            in_right.push_back(in[i]);
            pre_right.push_back(pre[i]);
        }
        //递归对左右子树的重建；最后就是对整个树的重建；
        pRoot->left=reConstructBinaryTree(pre_left,in_left);
        pRoot->right=reConstructBinaryTree(pre_right,in_right);
         
        return pRoot;
    }
        
     
};
