class Solution {
public:
    int Fibonacci(int n) 
    {
        vector<int>dp(n+1,0);
        dp[1]=1;
        //dp[2]=1;
        for(int i=2;i<=n;i++)
            dp[i]=dp[i-1]+dp[i-2];
        return dp[n];
    }
};
