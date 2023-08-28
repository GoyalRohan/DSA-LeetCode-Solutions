class Solution {
public:
    
    void dfs(int node , vector<int> &vis, set<int> &safe, vector<vector<int>>& graph)
    {
        vis[node] = true ; 
        bool allsafe = true ; 
        
        for(auto it : graph[node])
        {
            if(!vis[it])
            {
                dfs(it , vis , safe, graph) ;    
            }
         
            if(safe.find(it) == safe.end())
            {
                allsafe = false ; 
            }  
        }
        
        if(allsafe){
            // cout<<node<<endl ; 
            safe.insert(node) ;
        }
             
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size() ; 
        set<int> safe ; 
        vector<int> vis(n , 0) ; 
        
        
        for(int i=0 ; i<n ; i++)
        {
            if(vis[i] == 0)
                dfs(i , vis , safe , graph) ; 
        }
        
        vector<int> res ; 
        for(auto s : safe)
            res.push_back(s) ; 
        
        return res ; 
    }
};