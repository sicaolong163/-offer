class Solution {
public:
     
    /*vector<int> maxInWindows(const vector<int>& nums, unsigned int size)
    {
        int n=nums.size();
        vector<int>result;
        if(n<size||n==0||size==0)
            return result;
        deque<int>q;
        //1、滑动窗口的大小小于size的时候没有元素打印；
        for(int i=0;i<size;i++)
        {
            while(q.size()&&nums[i]>=nums[q.back()])//小于要入队的元素的元素 通通出队；从尾部出队；
                q.pop_back();
            q.push_back(i);//将这个元素入队；（从尾部入队）
        }
        //2 当窗口的大小 大于等于size的时候
        for(int i=size;i<n;i++)
        {
            result.push_back(nums[q.front()]);//首先将第一个最大的元素压入数组；
            while(q.size()&&nums[i]>=nums[q.back()])//然后继续判断是否出队
                q.pop_back();
            while(q.size()&&q.front()<=(int)(i-size))//判断队首是否出队；
                q.pop_front();
            q.push_back(i);//将这个元素的索引入队；
        }
           result.push_back(nums[q.front()]);//将队首压入数组；
        return result;
    }
    */
    vector<int> maxInWindows(const vector<int>& nums, unsigned int size)
    {
        int n=nums.size();
        vector<int>result;
        if(n<size||n==0||size==0)
            return result;
        for(int i=0;i<=n-size;i++)
        {
            int max=nums[i];
            for(int j=i;j<i+size;j++)
            {
                if(nums[j]>max)
                    max=nums[j];
            }
            result.push_back(max);
        }
        return result;
         
    }
     
};
