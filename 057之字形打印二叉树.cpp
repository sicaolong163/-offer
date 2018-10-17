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
    //必须得用栈 可以纸上模拟一下  用队列是不可以的；因为每一次有一个颠倒的过程
    vector<vector<int> > Print(TreeNode* pRoot)
    {
        vector<vector<int> >res;
        if(!pRoot)return res;
        stack<TreeNode *>q[2];
       TreeNode*node=pRoot;
        int cur=0,next=1;
        q[0].push(node);
        vector<int>v;
        while(q[cur].size()||q[next].size())
        {
            TreeNode *temp=q[cur].top();
            v.push_back(temp->val);
            q[cur].pop();
            if(cur==1)
            {
                if(temp->right)
                    q[next].push(temp->right);
                if(temp->left)
                    q[next].push(temp->left);
            }
            else if(cur==0)
            {
                if(temp->left)
                    q[next].push(temp->left);
                 if(temp->right)
                    q[next].push(temp->right);
            }
            if(q[cur].empty())
            {
                res.push_back(v);
                cur=next;
                next=1-next;
                v.clear();
            }
        }
        return res;
    }
    
};
