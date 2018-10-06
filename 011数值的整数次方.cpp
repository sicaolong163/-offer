class Solution {
public:
    double my_power(double base,unsigned int exponent)
    {
        vector<double>dp(exponent+1,1);
        dp[0]=1;
        for(int i=1;i<=exponent;i++)
            dp[i]=dp[i-1]*base;
        return dp[exponent];
    }
    double Power(double base, int exponent) 
    {
        if(base==0&&exponent<0)
            return 0;
        int fbs=abs(exponent);
        if(exponent>=0)
            return my_power(base,exponent);
        else
            return 1/my_power(base,fbs);
    }
};
