class Solution {
public:
    
    vector<vector<int>> ans ; 
    
    void dfs(int node, int par, int &timer , vector<int> &disc, vector<int> &low, vector<int> &vis, vector<int> &parent, vector<int> adj[] )
    {
        vis[node] = true ; 
        disc[node] = low[node] = timer++ ; 
        
        for(auto nbr : adj[node])
        {
            if(nbr == par)
                continue ; 
            if(!vis[nbr])
            {
                dfs(nbr , node , timer , disc , low ,  vis , parent , adj) ; 
                
                // Change if BackEdge
                low[node] = min(low[node] , low[nbr]) ; 
                // Check for bridge
                if(low[nbr] > disc[node])
                {
                    ans.push_back({node , nbr}) ; 
                }
            }
            else
            {
                low[node] = min(low[node] , disc[nbr]) ; 
            }
        }
    }
    
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        vector<int> adj[n] ; 
        
        for(auto edge : connections)
        {
            int u = edge[0] , v = edge[1] ; 
            adj[u].push_back(v) ; 
            adj[v].push_back(u) ; 
        }
        
        vector<int> low(n , -1) , disc(n , -1) , vis(n , 0) , parent(n , -1) ;
        int timer = 0 ; 
        
        for(int i=0 ; i<n ; i++)
        {
            if(!vis[i])
                dfs(i , -1, timer , disc , low , vis , parent , adj) ; 
        }
        
        return ans ; 
    }
};