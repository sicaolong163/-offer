 /*
        1、整体翻转
        2、将开始的空格去掉；
        3、查找翻转的范围
        4、进行翻转
        5、更新开始的范围；
    */
    string ReverseSentence(string str) 
    {
        string res;
        const int n=str.size();
        if(n==0)return "";
        reverse(str.begin(),str.end());//1、整体翻转
        int start,end,index=0;
        while(index<n)
        {
            while(str[index]==' '&&index<n)//2、将首字母为空格的去掉；并且更新起始的位置；
                index++;
            start=end=index;
            while(index<n&&str[index]!=' ')//3、然后查找翻转的范围；
            {
                end++;
                index++;
            }
            for(int i=start,j=end-1;i<j;i++,j--)//4、进行反转；
                swap(str[i],str[j]);
            start=end;//5、更新起始的位置；
        }
        return str;
    }
