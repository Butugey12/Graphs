class Solution {

public:

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m =grid[0].size();
        int vis[n][m];
        queue<pair<pair<int,int> , int>>q;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j]==2){
                    q.push({{i , j} , 0});
                    vis[i][j]=2;
                }
                else {
                    vis[i][j]=0;
                }
            }
        }
        int t=0;
        while(!q.empty()) {
            int row=q.front().first.first;
            int col =q.front().first.second;
            int time = q.front().second;
            t= max(time , t); //the backbone of this problem
            // now check the neighbouring guys to see if they have fresh oranges
            //look up first
            q.pop();
            if(row-1 >=0 && row-1<n && vis[row-1][col]!=2 && grid[row-1][col]==1){
                vis[row-1][col]=2;
                q.push({{row-1 , col},t+1});
            }
            //looking down
            if(row+1>=0 && row+1<n && vis[row+1][col]!=2 && grid[row+1][col]==1){
                vis[row+1][col]=2;
                q.push({{row+1,col},t+1});
            }
            //looking left
            if(col-1>=0 &&col-1 <m && vis[row][col-1]!=2 && grid[row][col-1]==1){
                vis[row][col-1]=2;
                q.push({{row,col-1},t+1});
            }
            //looking right 
            if(col+1>=0 && col+1 <m && vis[row][col+1]!=2 && grid[row][col+1]==1){
                vis[row][col+1]=2;
                q.push({{row,col+1},t+1});
            }
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(vis[i][j]==0 && grid[i][j]==1) return -1;
            }
        }
        return t;

    }
    
};
