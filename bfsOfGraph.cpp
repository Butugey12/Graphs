class Solution {
  public:
    
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> visited (V, 0);
        vector<int> res;
        visited[0]=1;
        queue<int> q;
        q.push(0);
        while(!q.empty() ) {
            int node = q.front();
            q.pop();
            res.push_back(node);
            
            for(int it : adj[node]) {
                if(!visited[it]) {
                    q.push(it);
                    visited[it]=1;
                }
            }
        }
        return res;
    }
    
};
