class Solution {
public:
    
    bool dfs(int node , vector<int> &vis, vector<int> &dfsvis, vector<int> &isPresentCycle, vector<vector<int>>& graph)
    {
        vis[node] = true ; 
        dfsvis[node] = true; 
        
        for(auto it : graph[node])
        {
            if(!vis[it])
            {
                if(dfs(it , vis , dfsvis, isPresentCycle, graph)) 
                    return isPresentCycle[node] = true ; 
            }
            else if(dfsvis[it])
                return isPresentCycle[node] = true ; 
            
        }
        
        dfsvis[node] = false ; 
        return false ; 
             
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size() ; 
        vector<int> vis(n , 0) , dfsvis(n , 0) , isPresentCycle(n , 0); 
        
        
        for(int i=0 ; i<n ; i++)
        {
            if(vis[i] == 0)
                dfs(i , vis , dfsvis , isPresentCycle, graph) ; 
        }
        
        vector<int> res ; 
        for(int i=0 ; i<n ; i++)
        {
            if(isPresentCycle[i] == false)
                res.push_back(i) ; 
        }
        
        return res ; 
    }
};