class Solution {
  private:
    bool dfs(int node , vector<int> adj[] , int vis[] , int pathVis[]) {
        vis[node]=1;
        pathVis[node]=1;
        
        // loop through the adjacency list
        for(auto it: adj[node]) {
            // if not visited then call the recursive function
            if(!vis[it]) {
                if(dfs(it, adj , vis , pathVis) == true)
                    return true;
            }
            // if visited and patVis then return true
            else if(vis[it] && pathVis[it]) {
                return true;
            }
        }
        pathVis[node]=0;
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        int vis[V]={0};
        int pathVis[V] ={0};
        for(int i=0;i<V;i++) {
            if(!vis[i]) {
                if(dfs(i , adj , vis , pathVis)==true) return true;
            }
        }
        return false;
    }
};
