class Solution {
private:
    int n,m;
    vector<vector<bool>>visited;
    int d[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
    bool isOk(int x,int y){return x>=0&&x<n&&y>=0&&y<m;}
    bool dfs(char* matrix, int startx, int starty,int index,char *str )
    {
        if(index==strlen(str)-1)
            return str[index]==matrix[startx*m+starty];
        if(str[index]==matrix[startx*m+starty])
        {
            visited[startx][starty]=true;
            for(int i=0;i<4;i++)
            {
                int newx=startx+d[i][0];
                int newy=starty+d[i][1];
                if(isOk(newx,newy)&&!visited[newx][newy]&&dfs(matrix,newx,newy,index+1,str))
                    return true;
            }
            visited[startx][starty]=false;
        }
        
        return false;
    }
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        if(rows==0||cols==0||str==nullptr)return false;
        n=rows,m=cols;
        visited=vector<vector<bool>>(n+1,vector<bool>(m+1,false));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(dfs(matrix,i,j,0,str))
                    return true;
            }
        }
        return false;
    }


};
