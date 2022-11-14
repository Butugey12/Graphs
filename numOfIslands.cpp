    void bfs(int i , int j , vector<vector<int>>&vis , vector<vector<char>>& grid) {
        // the steps are
        // mark the current position as visited 
        // create a queue and it should take the i and j 
        // but how will you store 2 ints in one space ? use pair
        // add it to the queue
        // while the queue is not empty
        // first remove the current element in this queue
        // then add the neighbours givcen that they are land 
        // land is shown by '1' and water is shown by '0'
        // make the required logic for this 
        // make sure the neighbour elements are elements that exist ;
        // check all directions 
        // and at any direction if you see that an element is a land 
        // add it to the queue
        int n = grid.size();
        int m = grid[0].size();
        vis[i][j] = 1;
        queue<pair<int,int>> q;
        q.push({i , j});

        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            // now traverse thriugh the possible neighbours
            for(int delrow=-1;delrow<=1;delrow++) {
                for(int delcol=-1;delcol<=1;delcol++) {
                    // now check whether the neighbour is in the boounds and whether it
                    // is land
                    int nrow = delrow+ row;
                    int ncol = delcol+col;
                    if(nrow>=0 && nrow<n &&
                        ncol>=0 && ncol<m &&
                        grid[nrow][ncol]=='1' 
                        && !vis[nrow][ncol]) {
                            vis[nrow][ncol] = 1;
                            q.push({nrow,ncol});

                        }
                }
            }
        }

        }
    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n , vector<int> (m ,0) );

        int cnt=0;
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
               if(!visited[i][j] && grid[i][j]=='1'){
                   cnt++;
                   bfs(i , j , visited , grid);
                   //cnt++;
               } 
            }
        }
        return cnt;
        
    }
