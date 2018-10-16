class Solution {
public:
//一、递归的思路；
    bool match(char* str, char* pattern)
    {
        if(!str&&!pattern)return true;
        if(!str||!pattern)return false;
        if(*str=='\0'&&*pattern=='\0')return true;
        if(*str!='\0'&&*pattern=='\0')return false;
        
        if(*(pattern+1)=='*')
        {
            if(*str!='\0'&&*pattern=='.'||*pattern==*str)//=='.'在前面；
                return match(str,pattern+2)||match(str+1,pattern+2)||match(str+1,pattern);
            else
                return match(str,pattern+2);
        }
        else if(*str!='\0'&&*pattern=='.'||*pattern==*str)
            return match(str+1,pattern+1);
        return false;
            
    }
    //dp的思想；
    bool isMatch(string s, string p) 
    {
        int n=s.size();
        int m=p.size();
        vector<vector<bool>>dp(n+1,vector<bool>(m+1,false));
        dp[0][0]=true;//初始化的时候为true；没有的字符串的时候是true；
        for(int i=0;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(p[j-1]=='*')
                    dp[i][j]=dp[i][j-2]||(i>0&&(p[j-2]==s[i-1]||p[j-2]=='.')&&dp[i-1][j]);
                else
                    dp[i][j]=(i>0&&(p[j-1]==s[i-1]||p[j-1]=='.')&&dp[i-1][j-1]);
            }
        }
        return dp[n][m];
    }
};
