class Solution {
public:
bool isValid(vector<vector<int>>& grid, int i, int j, int n, int m)
    {
        if(i>=0 && i<n && j>=0 && j<m && grid[i][j]==1)
        {
            return true;
        }
        return false;
    }
    
    void dfs(vector<vector<int>>& grid, int i, int j, int n, int m)
    {
       grid[i][j]=0;//mark the visited cells to 0 because we reached they are connectd to the boundaries and we did not need these cells
       if(isValid(grid,i+1,j,n,m))//to check the cell is valid or not
       {
           dfs(grid,i+1,j,n,m);
       }
       if(isValid(grid,i-1,j,n,m))
       {
           dfs(grid,i-1,j,n,m);
       }
        if(isValid(grid,i,j+1,n,m))
       {
           dfs(grid,i,j+1,n,m);
       }
        if(isValid(grid,i,j-1,n,m))
       {
           dfs(grid,i,j-1,n,m);
       }
    }
    
    int numEnclaves(vector<vector<int>>& grid) 
    {
       int n=grid.size();
       int m=grid[0].size();
       // We will only traverse the boundaries of the matrix  
       for(int i=0;i<n;i++)//for traversing top to bottom 
       {
           int j=0;//for left hand side -> top to bottom
           if(grid[i][j]==1)
           {
               dfs(grid,i,j,n,m);
           }
           
           j=m-1;//for right hand side -> top to bottom
           if(grid[i][j]==1)
           {
              dfs(grid,i,j,n,m); 
           }
       }
        
       for(int j=0;j<m;j++)//for traversing left to right
       {
           int i=0;// for top -> left to right
           if(grid[i][j]==1)
           {
               dfs(grid,i,j,n,m);
           }
           
           i=n-1;// for bottom ->left to right
           if(grid[i][j]==1)
           {
               dfs(grid,i,j,n,m);
           }
       }
    //Now Simply count the numbers of 1's in the matrix
    int area=0;
    for(int i=0; i<grid.size();i++)
      {
          for(int j=0;j<grid[i].size();j++)
          {
              if(grid[i][j]==1)
                  area++;
          }
      }
    
     return area;
  }
    
};
/*
// this is my code which is very similar to the above but mine doesnt pass all the test cases somehow.
class Solution {
  void dfs(int row , int col , vector<vector<int>>& grid , vector<vector<int>>& vis) {
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col]=1;
        grid[row][col]=0;
        
        // look up
        if(row-1 >=0 && row-1 <n && !vis[row-1][col] && grid[row-1][col]==1) {
            dfs(row-1 , col , grid , vis);
        }
        // look down
        if(row+1 >=0 && row+1 <n && !vis[row+1][col] && grid[row+1][col]==1) {
            dfs(row+1 , col , grid , vis);
        }
        // look left
        if(col-1 >=0 && col-1 <m && !vis[row][col-1] && grid[row][col-1]==1) {
            dfs(row , col-1 , grid , vis);
        }
        // look right
        if(col+1 >=0 && col+1 <m && !vis[row][col+1] && grid[row][col+1]==1) {
            dfs(row , col+1 , grid , vis);
        }
    }
public:
    int numberOfEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int> (m , 0));
        // first row and last row
        for(int i;i<m;i++) {
            // first row
            if(!vis[0][i] && grid[0][i]==1) {
                dfs(0,i,grid,vis);
            }
            // last row
            if(!vis[n-1][i] && grid[n-1][i]==1) {
                dfs(n-1,i , grid,vis);
            }
        }
        // traverse through the columns at the boubdaries
        for(int i=0;i<n;i++) {
            if(!vis[i][0] && grid[i][0]==1) {
                dfs(i , 0 , grid , vis);
            }
            // last column
            if(!vis[i][m-1] && grid[i][m-1]==1) {
                dfs(i,m-1 ,grid , vis);
            }
        }
        int count=0;
        // traverse through everything now and count them
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if( grid[i][j]==1 && vis[i][j]==0 ){
                    count++;
                }
            }
        }
        return count;
    }
};
*/
