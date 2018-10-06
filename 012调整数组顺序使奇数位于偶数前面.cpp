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
