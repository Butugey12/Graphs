class Solution {
private: 
    void dfs(int i , int j , vector<vector<char>>& board , vector<vector<int>> &vis ) {
        vis[i][j]=1;
        // now go all four sides and check if you can go to them
        int n = board.size();
        int m = board[0].size();
        // go up; row-1 col
        if(i-1>=0 && i-1 < n &&  !vis[i-1][j] && board[i-1][j]=='O') {
          
            dfs(i-1 , j,board,vis);
        }
        // go down
        if(i+1>=0 && i+1<n && !vis[i+1][j] &&board[i+1][j]=='O') {
            dfs(i+1, j , board,vis);
        }
        // go right
        if(j+1 >=0 && j+1 <m && !vis[i][j+1] && board[i][j+1]=='O') {
            dfs(i,j+1,board,vis);
        }
        // go left
        if(j-1 >=0 && j-1<m && !vis[i][j-1] && board[i][j-1]=='O') {
            dfs(i,j-1,board,vis);
        }
    }
public:

    void solve(vector<vector<char>>& board) {
        // go through the first column in search of a 'O';
        // go through the first row in search of a 'O';
        //
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis (n , vector<int>(m,0));
        // loop through the first row and last row
        for(int i=0;i<m;i++) {
            // first row
            if(board[0][i]=='O' && !vis[0][i] ) {
                vis[0][i]=1;
                dfs(0,i, board, vis);
            }
            if(!vis[n-1][i] && board[n-1][i]=='O')  {
                vis[n-1][i]= 1;
                dfs(n-1 , i , board , vis);
            }
        }
        // loop through the first and last column ;
        for(int i=0;i<n;i++) {
            // first column
            if(board[i][0]=='O' && !vis[i][0]) {
                vis[i][0]=1;
                dfs(i,0,board,vis);
            }
            // last column
            if(board[i][m-1]=='O' && !vis[i][m-1]) {
                vis[i][m-1]=1;
                dfs(i,m-1,board,vis);
            }
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<m ;j++) {
                if(board[i][j]=='O' && !vis[i][j]) {
                    board[i][j]='X';
                }
            }
        }
    }
};
