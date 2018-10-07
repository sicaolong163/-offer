/*

题目描述
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，
例如，如果输入如下4 X 4矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 
则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.

*/
//其中重要的是  中间的区别的大小的保证 ；第一个不需要  第二、三、四个 都需要保证；
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) 
    {
       vector<int>result;
        int rows=matrix.size();
        //assert(rows>0);
        int cols=matrix[0].size();
        int left=0,right=cols-1;
        int top=0,buttom=rows-1;
        while(left<=right&&top<=buttom)
        {
            //left--->right
            for(int i=left;i<=right;i++)
                result.push_back(matrix[top][i]);
            //top---->buttom
            if(top<buttom)//这个一定要保证；
                for(int i=top+1;i<=buttom;i++)
                    result.push_back(matrix[i][right]);
            //right--->left;
            if(left<right&&top<buttom)//这个一定要保证；
                for(int i=right-1;i>=left;i--)
                    result.push_back(matrix[buttom][i]);
            //buttom--->top
            if(left<right&&top<buttom)//这个一定要保证；
                for(int i=buttom-1;i>=top+1;i--)
                    result.push_back(matrix[i][left]);
            left++,right--;
            top++,buttom--;
        }
        return result;
    }
};
