class Solution {
    
  private:
    void dfs(int node , vector<int> &adj[] , int &vis[]) {
        vis[node ] = 1;
        for(auto it :adj[node]) {
            if(!vis[it]) {
                dfs(it , adj ,vis);
            }
        }
    }
    void bfs(vector<int> adjList[] , int visited[] , int s) {
        queue<int>q;
        q.push(s);
        visited[s]=1;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for(auto it:adjList[node]) {
                if(!visited[it]) {
                    q.push(it);
                    visited[it]=1;
                }
            }
        }
        
        
    }
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
       vector<int> adjList[V];
       for(int i=0;i<V;i++) {
           for(int j=0;j<V;j++) {
               if(adj[i][j]==1 && i!=j) {
                   adjList[i].push_back(j);
                   adjList[j].push_back(i);
               }
           }
       }
       //visited array
       int cnt=0;
       int vis[V] ={0};
       for(int i=0;i<V;i++) {
           if(!vis[i]){
               cnt++;
               dfs(i , adjList, vis);
           }
       }
       return cnt;
    }
};
