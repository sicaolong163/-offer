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
    vector<int> PrintFromTopToBottom(TreeNode* root)
    {
        vector<int>result;
        if(!root)
            return result;
        queue<TreeNode *>queue;
        queue.push(root);
        while(!queue.empty())
        {
            TreeNode *node=queue.front();
            queue.pop();
            result.push_back(node->val);
            if(node->left)
                queue.push(node->left);
            if(node->right)
                queue.push(node->right);
        }
        return result;
    }
};
