/*
    题目描述
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，并保证奇数和奇数，
偶数和偶数之间的相对位置不变。
*/
class Solution {
public:
    /*bool isOdd(int number)
    {
        if(number&1)
            return true;
        return false;
    }
    void reOrderArray(vector<int> &array) 
    {
        int n=array.size();
        if(n==0)return ;
        vector<int>odd;
        vector<int>even;
        for(int i=0;i<n;i++)
        {
            if(isOdd(array[i]))
                odd.push_back(array[i]);
            else
                even.push_back(array[i]);
        }
        for(int i=0;i<odd.size();i++)
            array[i]=odd[i];
        for(int i=odd.size();i<odd.size()+even.size();i++)
            array[i]=even[i-odd.size()];
    }
    */
    bool isOdd(int number)
    {
        if(number&1)
            return true;
        return false;
    }
   
    void reOrderArray(vector<int> &array) 
    {
         int n=array.size();
        if(n==0)return ;
        for(int i=0;i<n;i++)
        {
            for(int j=n-1;j>i;j--)
            {
                if( !isOdd(array[j-1])&&isOdd(array[j])  )
                    swap(array[j],array[j-1]);
            }
        }
    }
    
    /*static bool isOdd(int number)
    {
        if(number&1)
            return true;
        return false;
    }
    void reOrderArray(vector<int> &array) 
    {
        stable_partition(array.begin(),array.end(),isOdd);
    }
    */
};
