//You are given a connected undirected graph. Perform a Depth First Traversal of the graph.
//Note: Use a recursive approach to find the DFS traversal of the graph starting from the 0th vertex from left to right according to the graph.



class Solution {
  private:
    void dfs (int node , vector<int> adj[] , int vis[] , vector<int>&output) {
        vis[node ] = 1;
        output.push_back(node);
        for(auto it : adj[node] ) {
            if(!vis[it]) {
                dfs(it , adj , vis , output);

            }
        }
    }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        int start =0;
        int vis[V] ={0};
        vector<int>output;
        
        dfs(start , adj , vis , output);
        return output;
    }
};
