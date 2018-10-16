class Solution {
public:
//先排序，求出王的个数，然后求出顺子起始的位置，判断是否有重复，然后在求出gap的个数；
//判断王的个数是不是大于等于gap的个数；
    bool IsContinuous( vector<int> numbers ) 
    {
        const int n=numbers.size();
        if(n==0)return false;
        int kings=0;
        int gap=0;
        sort(numbers.begin(),numbers.end());
        for(auto i:numbers)
            if(i==0)
                kings++;
        int small=kings;
        int big=small+1;
        while(big<n)
        {
            if(numbers[big]==numbers[small])
                return false;
            gap+=numbers[big++]-numbers[small++]-1;
        }
        return kings>=gap?true:false;
    }
};
