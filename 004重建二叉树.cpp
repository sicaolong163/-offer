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
   TreeNode* dfs(vector<int> &pre,int start_pre,int end_pre,vector<int>&in,int start_in,int end_in)
   {
       if(start_pre>end_pre)return nullptr;
       TreeNode* root=new TreeNode(pre[start_pre]);
       int index;//找出头结点在中序遍历中的位置；
       for(int i=start_in;i<=end_in;i++)
       {
           if(in[i]==root->val)
           {
               index=i;
               break;
           }
       }
       int left_size=index-start_in;//计算左子树和右子树的长度；
       int right_size=end_in-index;
       root->left=dfs(pre,start_pre+1,start_pre+left_size,in,start_in,index-1);//递归调用；
       root->right=dfs(pre,start_pre+left_size+1,end_pre,in,index+1,end_in);//主要是这个范围一定要找好；不能出错；
       return root;
   }
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> in)
    {
       if(pre.size()==0||in.size()==0||pre.size()!=in.size())return nullptr;
        return dfs(pre,0,pre.size()-1,in,0,in.size()-1);
    }
};
