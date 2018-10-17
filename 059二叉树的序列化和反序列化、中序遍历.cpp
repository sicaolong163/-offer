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
/*
    中序遍历和递归的思想；
    其他的知识点：
        1、const_cast 强制类型转换； c_str()string 转char×；
        2、stoi(123qwe2)==123；
        3、string str(char *ch);可以转换成字符串；

*/
class Solution {
public:
    void Serialize(TreeNode *root,string &s)
    {
        if(!root)
        {
            s+='#';
            s+=',';
            return ;
        }
        s+=to_string(root->val);
        s+=',';
        Serialize(root->left,s);
        Serialize(root->right,s);
    }
    char* Serialize(TreeNode *root) 
    {    
        if(!root)return nullptr;
        string s;
        Serialize(root,s);
        char *res=new char[s.size()+1];
        strcpy(res,const_cast<char *>(s.c_str()));
        return res;
    }
    TreeNode *Deserialize(string &s)
    {
        if(s.empty())return nullptr;
        if(s[0]=='#')
        {
            s=s.substr(2);
            return nullptr;
        }
        TreeNode *root=new TreeNode (stoi(s));
        s=s.substr(s.find_first_of(',')+1);
        root->left=Deserialize(s);
        root->right=Deserialize(s);
        return root;
    }
    TreeNode* Deserialize(char *str) 
    {
        if(!str)return nullptr;
        string s(str);
        return Deserialize(s);
    }
};
