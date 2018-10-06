class Solution {
public:
    int minNumberInRotateArray(vector<int> nums) 
    {
        int  n=nums.size();
        if(n==0)return 0;
        int left=0;
        int right=n-1;
        int mid;
        mid=(right-left)/2+left;
        while(left<right-1)
        {
            mid=(right-left)/2+left;
           if(nums[mid]>=nums[left])
               left=mid;
           else if(nums[mid]<=nums[right])
                right=mid;
            if(right-left==1)
            {
                mid=right;
                break;
            }
        }
        return nums[mid];
    }
};
