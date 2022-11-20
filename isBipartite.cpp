class Solution {
private: 
    bool check(int start, vector<int>adj[] , int color[] ) {
         // Code here
	    
	    queue<int> q;
	    q.push(start);
	    color[start]=0;
	    while(!q.empty()) {
	        // go to the neighbours
	        // using the adjacency matrix;
	        int node = q.front();
	        q.pop();
	        for(auto it : adj[node]) {
	            // if the adjacent node is not colored
	            // then color it by the opposite color of your node
	            if(color[it]==-1 ) {
	                color[it] = !color[node];
	                q.push(it);
	            }
	            // if it is colored,
	            // then check if the 
	            else if( color[it]==color[node]) {
	                /// then it is not bipartite
	                return false;
	            }
	            
	        }
	    }
	    return true;
    }
public:
	bool isBipartite(int V, vector<int>adj[]){
	   int  color[V];
	   for(int i=0;i<V;i++) color[i]=-1;
	   for(int i=0;i<V;i++) {
	       if(check(i,adj,color) == false) {
	           return false;
	       }
	       
	   }
	   return true;
	}

};
