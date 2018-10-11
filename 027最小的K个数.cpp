class Solution {
public:
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
};
