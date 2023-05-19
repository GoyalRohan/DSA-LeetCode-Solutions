class Solution {
public:
    
    void dfs(int i, vector<int> &vis , vector<int> adj[])
    {
        vis[i] = 1 ; 
        for(auto it : adj[i])
        {
            if(vis[it] == 0)
                dfs(it , vis , adj) ; 
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> adj[n] ; 
        int edges = 0 ; 
        
        for(int i=0 ; i<connections.size() ; i++)
        {
            int u= connections[i][0] ; 
            int v= connections[i][1] ; 
            
            adj[u].push_back(v) ; 
            adj[v].push_back(u) ; 
            edges++ ; 
        }
        
        if(edges < n-1)
            return -1 ; 
        
        int components  = 0 ; 
        vector<int> vis(n, 0) ; 
        
        for(int i=0 ; i<n ; i++)
        {
            if(vis[i] == 0)
            {
                components++ ;
                dfs(i , vis, adj) ; 
            }
        }

        int red = edges - ((n-1) - (components-1)) ; 
        if(red >= (components - 1))
            return components - 1 ; 
        
        return -1 ; 
        
    }
};