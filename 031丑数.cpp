class Solution {
public:
    int min3(int a,int b,int c){return min(min(a,b),c);}
    int GetUglyNumber_Solution(int index) 
    {
        if(index==0)return 0;
        int times2=0,times3=0,times5=0;
        vector<int>nums(index+1);//用来存放丑数；
        nums[0]=1;
        for(int i=1;i<=index;i++)//感觉是动态规划的思想；
        {
           nums[i]=min3(2*nums[times2],3*nums[times3],5*nums[times5]);
            if(nums[i]==2*nums[times2])times2++;
            if(nums[i]==3*nums[times3])times3++;
            if(nums[i]==5*nums[times5])times5++;
        }
        return nums[index-1];
    }
};
