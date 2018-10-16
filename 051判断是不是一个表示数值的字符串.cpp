class Solution {
/*/思路：
    1、首先是判断是不是一个有符号的数字；
    2、有符号的数字又是一个无符号的数字组成的；
    3、怎么判断一个无符号的数字；
    4、注意其中的参数是引用 代表可以修改位置；
    e之后是一个有符号的数字；
    .之后是一个无符号的数字；
    */
private:
    bool isNum(char *&str)
    {
        if(*str=='+'||*str=='-')
            str++;
        return isUnsignedNum(str);
    }
    bool isUnsignedNum(char *&str)
    {
        char *start=str;
        while(isdigit(*str))
            str++;
        return str>start;
    }
public:
    bool isNumeric(char* string)
    {
        if(!string)return true;
        bool res=isNum(string);
        if(*string=='.')
        {
            string++;
            res=isUnsignedNum(string)||res;
        }
        if(*string=='e'||*string=='E')
        {
            string++;
            res=isNum(string)&&res;
        }
        return res&&*string=='\0';
    }

};
