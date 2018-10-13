/*
求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？
为此他特别数了一下1~13中包含1的数字有1、10、11、12、13因此共出现6次,
但是对于后面问题他就没辙了。
ACMer希望你们帮帮他,并把问题更加普遍化,可以很快的求出任意非负整数区间中1出现的次数（从1 到 n 中1出现的次数）。
*/
class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
            int res=0;
        if(n==0)return res;
        int left,cur;//左侧和当前位的值；
        left=n;
        int base=1;
        while(left>0)
        {
            cur=left%10;//求每一个当前位的值；
            left=left/10;//左侧值每次更新；
            if(cur<1)
                res+=left*base;
            else if(cur==1)
                res+=left*base+n%base+1;//==1的时候有高位值×base 和低位值+1；
            else
                res+=(left+1)*base;
            base*=10;//基数更新；
        }
        return res;
    }
};
