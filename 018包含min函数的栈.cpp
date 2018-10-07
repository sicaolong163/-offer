/*
  题目描述
定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。
*/
//注意压入的时候 要考虑是否是空的；
class Solution {
public:
    void push(int value) 
    {
         if(min_stk.empty())
              min_stk.push(value);
         else if(value<min_stk.top())
            min_stk.push(value);
        stk.push(value);
    }
    void pop() 
    {
       
            
        if(stk.top()==min_stk.top())
            min_stk.pop();
        stk.pop();
    }
    int top()
    {
        return stk.top();
    }
    int min() 
    {
        return min_stk.top();
    }
   private:
    stack<int>stk;
    stack<int>min_stk;
};
