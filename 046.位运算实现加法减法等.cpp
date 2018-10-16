/*
  位运算：
  & 与运算
  | 或运算
  ^异或运算
  ～取反运算；
  <<左移运算符；
  >>右移运算符；
 
  
*/
class Solution {
public:
    int Add(int num1, int num2)
    {
        while(num2)
        {
            int temp1=num1^num2;//不带仅为  抑或运算；
            int temp2=num1&num2;//只带仅为 进位并<<一位；
            num1=temp1;
            num2=temp2<<1;
        }
        return num1;
    }
};

void  my_fun
{
  //1、位运算实现乘法：
  int a=2;
  a<<1==a*2;
//2、交换两个数：
  void swap(int a,int b)
  {
    a^=b;
    b^=a;
    a^=b;
  }
  //3、位操作判断奇数偶数
  //4、位操作 交换符号
    int reversal(int a){return ~a+1;}
}
