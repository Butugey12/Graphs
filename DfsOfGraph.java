class solution {
  
  public static void dfs(int node , boolean[] vis , ArrayList<ArrayList<Integer>> adj , ArrayList<Integer> lis) {
     
      vis[node] = true;
      lis.add(node);
      for(Integer it : adj.get(node) ) {
         if( vis[it]==false ) {
            dfs(it , vis , adj , lis); 
           
         }
        
      }
  }
  public ArrayList<Integer> dfsOfGraph(int V ,  ArrayList<ArrayList<Integer>> adj) {
    boolean[] vis = new boolean[V+1];
    vis[0] = true;
    ArrayList<Integer> ls = new ArrayList<>();
    dfs(0,vis, adj , ls);
    return ls
    
    
    
  }
}
