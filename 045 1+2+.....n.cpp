class Solution {
public:
    int Sum_Solution(int n) 
    {
        if(n==1)
            return 1;
        return n+Sum_Solution(n-1);
    }
    int Sum_Solution(int n) 
    {
        return (n+1)*n/2;
    }
};
