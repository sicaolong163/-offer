class Solution {
public:
    int FirstNotRepeatingChar(string str)
    {
        const int n=str.size();
        if(n==0)return -1;
        int dict[128]={0};
        for(auto i:str)
            dict[i]++;
        for(int i=0;i<n;i++)
            if(dict[str[i]]==1)
                return i;
         return 0;
    }
};
