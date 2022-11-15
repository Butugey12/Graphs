class Solution {
  public:
    bool bfs(int src , vector<int> adj[], int vis[]) {
        queue<pair<int, int>>q;
        q.push({src,-1});
        vis[src]=1;
        
        while(!q.empty()) {
            int node =q.front().first;
            int parent=q.front().second;
            q.pop();
            for(int it : adj[node]) {
                if(!vis[it]) {
                    q.push({it , node});
                    vis[it]=1;
                }
                //if it is visited there is two possibilites
                // either it is a parent or someone else has alread visited it
                
                else if(parent!=it)  {
                    // this means that you are trying to visit a node
                    // that has been visited alrready that is not Your parent
                    return true;
                }
            }
            
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        int vis[V] = {0};
        for(int i=0;i<V;i++) {
            if(!vis[i]) {
                if(bfs(i , adj , vis))return true;
            }
        }
        return false;
        
    }
};
