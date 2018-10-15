class Solution {
public:
//字符串拼接
    string LeftRotateString(string str, int n) 
    {
        const int len=str.size();
        if(len==0)return "";
        n=n%len;
        string str1=str.substr(0,n);
        string str2=str.substr(n,len-n+1);
        return str2+str1;
    }
   //字符交换，（XY）T=(XTYT)T;
    string LeftRotateString(string str, int n) 
    {
        const int len=str.size();
        if(len==0)return "";
        n=n%len;
        for(int i=0,j=n-1;i<j;i++,j--)swap(str[i],str[j]);
        for(int i=n,j=len-1;i<j;i++,j--)swap(str[i],str[j]);
        for(int i=0,j=len-1;i<j;i++,j--)swap(str[i],str[j]);
        return str;
    }
};  
