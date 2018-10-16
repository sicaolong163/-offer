class Solution {
//分为左右两部分 上三角形和下三角形  dp的思想；
public:
    vector<int> multiply(const vector<int>& A) 
    {
        const int n=A.size();
        vector<int>res;
        vector<int>left(n),right(n);
        left[0]=right[n-1]=1;
        for(int i=1;i<n;i++)
            left[i]=left[i-1]*A[i-1];
        for(int j=n-2;j>=0;j--)
            right[j]=right[j+1]*A[j+1];
        res=left;
        for(int i=0;i<n;i++)
            res[i]*=right[i];
        return res;
    }
};
