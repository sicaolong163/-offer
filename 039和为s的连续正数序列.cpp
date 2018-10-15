class Solution {
public:
//滑动窗口
    vector<vector<int> > FindContinuousSequence(int sum) 
    {
        vector<vector<int> >res;
        if(sum<=2)return res;
        int left=1,right=-1;
        int cur=0;
        
        while(left<sum)
        {
            if(cur<sum&&right+1<sum)
                cur+=++right;
            else
                cur-=left++;
            if(cur==sum)
            {
                vector<int>temp;
                for(int i=left;i<=right;i++)
                    temp.push_back(i);
                res.push_back(temp);
            }
        }
        return res;
    }
};
