/*
  请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
*/
class Solution {
public:
	void replaceSpace(char *str,int length) 
    {
        if(!str||length<0)return ;
        int oldLength=0;
        int numSpace=0;
        int i=0;
        while(str[i]!='\0')
        {
            if(str[i]==' ')
                numSpace++;
            i++;
            oldLength++;
        }
        
        int newLength=oldLength+numSpace*2;
        if(newLength>length)return ;
        int oldIndex=oldLength;
        int newIndex=newLength;
        while(newIndex>oldIndex&&oldIndex>=0)
        {
            if(str[oldIndex]==' ')
            {
                str[newIndex--]='0';
                str[newIndex--]='2';
                str[newIndex--]='%';
            }
            else
                str[newIndex--]=str[oldIndex];
            oldIndex--;
        }
	}
};
