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
private:
    vector<vector<int> >result;
    void dfs(TreeNode* root,int sum,vector<int>&temp)
    {
        if(root==nullptr)return ;
        if(!root->left&&!root->right)
        {
            if(root->val==sum)
            { 
                temp.push_back(root->val);
                result.push_back(temp);
                temp.pop_back();
            }
        }
       temp.push_back(root->val);
        dfs(root->left,sum-root->val,temp);
        dfs(root->right,sum-root->val,temp);
        temp.pop_back();
    }
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) 
    {
        if(!root)return result;
        vector<int>temp;
        dfs(root,expectNumber,temp);
        return result;
    }
};
