class Solution {
public:
    bool helper(vector<int>&nums,int start,int end)
    {
        if(start>=end)return true;
        int i=start;
        int root=nums[end];
        //找到左子树和右字数的分割点；
        while(i<end&&nums[i]<root)
            i++;
        for(int j=i;j<end;j++)
        {
            if(nums[j]<root)
                return false;
        }
        return helper(nums,start,i-1)&&helper(nums,i,end-1);

    }
    bool VerifySquenceOfBST(vector<int> sequence) 
    {
        if(sequence.size()==0)return false;
        return helper(sequence,0,sequence.size()-1);
    }
};
