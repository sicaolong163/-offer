class Solution {
public:
//1、map的方法 容易想到的；
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) 
    {
        vector<int> res;
        map<int,int>map;
        if(data.empty())return ;
        for(auto i:data)
            map[i]++;
        for(auto i:data)
        {
            if(map[i]==1)
                res.push_back(i);
        }
        *num1=res[0];
        *num2=res[1];
    }
 //位运算的方法（技术流）
  int get_first_bit(int num)
    {
        if(num==0)return 0;
        int index=0;
        while((num&1)==0)
        {
            index++;
            num=num>>1;
        }
        return index;
    }
    bool isBits(int a,int index)
    {
        return ((a>>index)&1)==1;
    }
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2)
    {
       // vector<int> res;
        if(data.empty())return ;
        int num=0;
        for(auto i:data)
            num^=i;
        int first=get_first_bit(num);
        vector<int>left,right;
        for(auto i:data)
        {
           if(isBits(i,first))
               left.push_back(i);
            else
                right.push_back(i);
        }
        *num1=*num2=0;
        for(auto i:left)
            *num1^=i;
        for(auto i:right)
            *num2^=i;
        
    }
};
