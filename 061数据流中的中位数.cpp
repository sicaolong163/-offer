class Solution {
private:
    priority_queue<int,vector<int>,less<int>>max;//最小堆；
    priority_queue<int,vector<int>,greater<int>>min;//最大堆；
public:
    void Insert(int num)
    {
        if(max.empty()||num<=max.top())
            max.push(num);
        else min.push(num);
        if(max.size()>min.size()+1)
        {
            int temp=max.top();
            max.pop();
            min.push(temp);
        }
        if(max.size()<min.size())
        {
            int temp=min.top();
            max.push(temp);
            min.pop();
        }
    }
    double GetMedian()
    { 
        return max.size()==min.size()?(max.top()+min.top())/2.0:max.top();
    }

};
