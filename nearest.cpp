class Solution 
{
    public:
    
    
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int n = grid.size();
	    int m = grid[0].size();
	    queue<pair<pair<int , int>, int>> q;
	    vector<vector<int>> distance(n , vector<int> (m,0));
	    vector<vector<int>> visited(n , vector<int> (m,0));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j]==1) {
                    q.push( {{i, j},0} );
                    visited[i][j]=1;
                }
                else {
                    visited[i][j]=0;
                }
            }
        }
        int t=0;
        while(!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            
            //first go to the dist array and set it to zero
            distance[row][col] = steps;
            // go check the 4 sides
            // look up and check 
            if(row-1>=0 && row-1 <n && !visited[row-1][col]  ) {
                visited[row-1][col]=1;
                q.push({{row-1,col},steps+1});
                // add it to the dist matrix
               
            }
            // look down and check
            if(row+1>=0 && row+1 <n && !visited[row+1][col] ) {
                visited[row+1][col]=1;
                q.push({{row+1,col},steps+1});
            }
            if(col-1>=0 && col-1 <m && !visited[row][col-1] ) {
                visited[row][col-1]=1;
                q.push({{row,col-1},steps+1});
            }
            if(col+1>=0 && col+1 <m && !visited[row][col+1]) {
                visited[row][col+1]=1;
                q.push({{row,col+1},steps+1});
            }
            
            
        
            
            
        }
	    return distance;
	}
};
