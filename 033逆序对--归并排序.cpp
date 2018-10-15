class Solution {
public:
    int InversePairs(vector<int> data)
    {
        int n=data.size();
        if(n==0||n==1)
            return 0;
        vector<int >copy(data);
        return InversePairs_help(data,copy,0,n-1)%1000000007;
    }
    long InversePairs_help(vector<int >&data,vector<int>&copy,int begin,int end)
    {
        if(begin>=end)return 0;
        int mid=(begin+end)/2;
        long num1=InversePairs_help(copy,data,begin,mid);
        long num2=InversePairs_help(copy,data,mid+1,end);
 
        int left=mid;
        int right=end;
        int index=end;
        long cnt=0;
          while(left>=begin&&right>=mid+1)
          {
              if(data[left]>data[right])
              {
                  copy[index--]=data[left--];
                  cnt+=right-mid;//到底这句话啥意思？就是当前的前面的也都是逆序的；因为这个前面的都比当前的小；
              }
              else
                  copy[index--]=data[right--];
          }
    
        while(left>=begin)
            copy[index--]=data[left--];
        while (right>=mid+1)
             copy[index--]=data[right--];
        return (num1+num2+cnt);
      
    }
};
