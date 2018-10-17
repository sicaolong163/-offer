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
//用队列保存；不用栈
class Solution {
public:
        vector<vector<int> > Print(TreeNode* pRoot) {
            vector<vector<int> >res;
            if(!pRoot)return res;
            TreeNode *node=pRoot;
            queue<TreeNode *>q[2];
            int cur=0,next=1;
            q[0].push(node);
            vector<int>temp;
            while(q[cur].size()||q[next].size())
            {
                TreeNode *pNode=q[cur].front();
                temp.push_back(pNode->val);
                q[cur].pop();
                if(pNode->left)
                    q[next].push(pNode->left);
                if(pNode->right)
                    q[next].push(pNode->right);
                if(q[cur].empty())
                {
                    res.push_back(temp);
                    temp.clear();
                    cur=next;
                    next=1-next;
                }
            }
        return res;
        }
    
};
