class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) 
    {
        int n=array.size();
        if(n==0)return 0;
        vector<int>dp(n,0);
        dp[0]=array[0];
        for(int i=1;i<n;i++)
        {
            if(dp[i-1]<0)
                dp[i]=array[i];
            else
                dp[i]=dp[i-1]+array[i];
        }
        return *max_element(dp.begin(),dp.end());
    }
};
