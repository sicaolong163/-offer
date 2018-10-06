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
