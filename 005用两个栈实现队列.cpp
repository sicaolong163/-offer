/*
 题目描述
用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
*/

class Solution
{
    //思路就是：一个栈表示入队操作一个栈表示出队操作；
public:
    void push(int node) 
    {
        stack1.push(node);
    }

    int pop()
    {
        if(stack2.empty())
        {
            while(stack1.size())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int temp=stack2.top();
        stack2.pop();
        return temp;
    }

private:
    stack<int> stack1;//用来入队；
    stack<int> stack2;//用来出队；
};
