class Solution {
private:
    vector<string>result;
    void dfs(string &str,int start,int end)
    {
        if(start==end)//终止的条件
        {
            result.push_back(str);
            return ;
        }
        for(int i=start;i<=end;i++)//
        {
            if(i!=start&&str[i]==str[start])
                continue;
            swap(str[i],str[start]);//处理
            dfs(str,start+1,end);//递归
            swap(str[i],str[start]);//回溯
        }
        return ;
    }
public:
    vector<string> Permutation(string str) 
    {
        if(str.empty())return result;
        dfs(str,0,str.size()-1);
        sort(result.begin(),result.end());
        return result;
    }
};
