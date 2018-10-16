class Solution {
public:
    int StrToInt(string str) 
    {
        const int n=str.size();
        if(n==0)return 0;
        int index=0;
        int sign=1;
        int res=0;
        while(str[index]==' ')
            index++;
        if(str[index]=='+')
            index++;
        else if(str[index]=='-')
        {
            index++;
            sign=-1;
        }
        for(int i=index;i<n;i++)
        {
            if(isdigit(str[i]))
                res=res*10+str[i]-'0';
            else
            {
                res=0;
                break;
            }
        }
        return res*sign;
    }
};
