class Solution {
public:
//公式： f（n,m）=(f(n-1,m)+m)%n;
    int LastRemaining_Solution(int n, int m)
    {
        if(n==0||m==0)return -1;
        vector<int>dp(n+1,0);
        dp[1]=0;
        for(int i=1;i<=n;i++)
            dp[i]=(dp[i-1]+m)%i;
        return dp[n];
    }
};
