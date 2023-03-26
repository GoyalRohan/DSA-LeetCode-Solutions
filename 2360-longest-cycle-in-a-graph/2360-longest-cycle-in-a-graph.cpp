class Solution {
public:
    
    void dfs(int node, int distance , int &ans, vector<int>& edges , vector<int> &vis , vector<int> &dfsvis , vector<int> &dist)
    {
        if(node != -1)
        {
            if(vis[node] == 0)
        {
            vis[node] = 1 ; dfsvis[node] = 1 ; 
            dist[node] = distance ; 
                dfs(edges[node] , distance+1 ,ans ,edges, vis,  dfsvis, dist) ; 
        }
        else if(dfsvis[node])
        {
            ans = max(ans , distance - dist[node]) ; 
        }
        
        dfsvis[node] = 0 ;
        }
        
    }
    
    int longestCycle(vector<int>& edges) {
        int n = edges.size() ; 
        vector<int> dist(n,0);
        vector<int> vis(n , 0) , dfsvis(n , 0) ; 
        int ans = -1 ; 
        
        for(int i=0 ; i<n ; i++)
        {
            if(vis[i] == 0)
            {
                dfs(i , 0 , ans, edges , vis , dfsvis, dist) ; 
            }
        }
        return ans ; 
        
    }
};