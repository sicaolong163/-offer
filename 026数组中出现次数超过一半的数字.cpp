class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) 
    {
        int n=numbers.size();
        if(n==0)return 0;
        int times=1;
        int num=numbers[0];
        for(int i=1;i<n;i++)
        {
            if(numbers[i]==num)
                times++;
            else
            {
                times--;
                if(times==0)
                {
                    num=numbers[i];
                    times=1;
                }
            }
        }
        int time=0;
        for(auto i:numbers)
            if(i==num)
                time++;
        if(time*2>n)
            return num;
        else
            return 0;
    }
};
