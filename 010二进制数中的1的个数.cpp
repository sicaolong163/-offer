/*   题目描述
     输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
*/
class Solution {
public:
     int  NumberOf1(int n) 
     {

         n=unsigned(n);
         //if(n==0)return 0;
         int count=0;
         while(n)
         {
             count++;
             n&=(n-1);
         }
         return count;
     }
};
