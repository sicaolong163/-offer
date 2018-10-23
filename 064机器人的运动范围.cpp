class Solution {
 private:
    int res;
    int n,m;
    vector<vector<bool>>visited;
    int d[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
    int get_sum(int x)
    {
        int sum=0;
        while(x)
        {
            sum+=x%10;
            x/=10;
        }
        return sum;
    }
    bool isOk(int threshold,int x,int y)
    {
        int sum1,sum2;
        if(x>=0&&x<n&&y>=0&&y<m)
        {
             sum1=get_sum(x);
             sum2=get_sum(y);
            return sum1+sum2<=threshold;
        }
        return false;
    }
    int dfs(int threshold, int rows, int cols,int r,int c )
    {
        int count=0;
        if(isOk(threshold,r,c)&&!visited[r][c])
        {
            visited[r][c]=true;
            count++;
            for(int i=0;i<4;i++)
            {
                int newx=r+d[i][0];
               int newy=c+d[i][1];
                count+=dfs(threshold,rows,cols,newx,newy);
            }
            //visited[r][c]=false;
        }
        return count;
    }
public:
    int movingCount(int threshold, int rows, int cols)
    {
        if(threshold==0||rows<=0||cols<=0)return res;
        n=rows,m=cols;
        visited= vector<vector<bool>>(n+1,vector<bool>(m+1,false));
        res=dfs(threshold,n,m ,0,0);
        return res;
    }
};
