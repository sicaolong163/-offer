class Solution {
public:
   //一|堆
    vector<int> GetLeastNumbers_Solution(vector<int> nums, int k) 
    {
        vector<int>result;
        int n=nums.size();
        if(n<k||n==0)return result;
        make_heap(nums.begin(),nums.end(),greater<int>());
        for(int i=0;i<k;i++)
        {
            make_heap(nums.begin(),nums.end(),greater<int>());
            result.push_back(nums.front());
            pop_heap(nums.begin(),nums.end());
            nums.pop_back();
            
            
        }
        return result;
    }
    //二、 优先队列
    vector<int> GetLeastNumbers_Solution(vector<int> nums, int k) 
    {
        vector<int>result;
        int n=nums.size();
        if(n<k||n==0)return result;
        priority_queue<int,vector<int>,greater<int>>q;
        for(int i=0;i<n;i++)
            q.push(nums[i]);
        while(q.size()>n-k)
        {
            result.push_back(q.top());
            q.pop();
        }
        return result;
    }
    //三、快排
    int partition(vector<int> &nums, int left,int right)
    {
        int pivort=nums[left];
        while(left<right)
        {
            while(left<right&&nums[right]>=pivort)
                right--;
            swap(nums[left],nums[right]);
            while(left<right&&nums[left]<=pivort)
                left++;
            swap(nums[left],nums[right]);
        }
        return left;
    }
    vector<int> GetLeastNumbers_Solution(vector<int> nums, int k) 
    {
         vector<int>result;
        int n=nums.size();
        if(n<k||n==0||k==0)//为什么这里不增加k==0  就超时啊？
            return result;
        int left=0;
        int right=n-1;
        int index=partition(nums,left,right);
       while(index != k-1)
       {
           if(index>k-1)
           {
               right=index-1;
               index=partition(nums,left,right);
           }
           else if(index<k-1)
           {
               left=index+1;
               index=partition(nums,left,right);
           }
       }
        
        for(int i=0;i<k;i++)
            result.push_back(nums[i]);
        return result;
    }
};
