class Solution {
public:
    
  

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int theColour = image[sr][sc];
        int n = image.size();
        int m = image[0].size();
        queue<pair<int,int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;
        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
             // look up--> row-1,col
               if( row-1 >=0 && row-1<n && image[row-1][col]==theColour &&image[row-1][col]!=color  ) {
                   // if true then change the value to color
                   image[row-1][col] = color;
                   q.push( {row-1 , col});
               }
               // look down , the row changes but the column is the same
               if(row+1>=0 && row+1 <n && image[row+1][col]==theColour &&image[row+1][col] !=color) {
                   image[row+1][col] = color;
                   q.push({row+1, col});
               }
               // look right , the row stays the same and the col becomes plus 1
               if(col+1 >=0 && col+1<m && image[row][col+1]==theColour &&image[row][col+1] !=color){
                   image[row][col+1] = color;
                   q.push({row,col+1});
               }
               // look left , the row stays the same but the col becomes -1
               if(col-1>=0 && col-1<m && image[row][col-1]==theColour &&image[row][col-1] !=color) {
                   image[row][col-1] = color;
                   q.push({row , col-1});
               }

        }
        return image;

    }
};
