class Solution {
public:
    
    int mx = 0 , ans = 0 ; 
    
    void dfs(int man,vector<int>& informTime , vector<int> adj[])
    {
        mx = max(mx , ans) ; 
        for(auto emp : adj[man])
        {
            ans += informTime[man] ; 
            dfs(emp , informTime, adj) ; 
            ans -= informTime[man] ; 
        }
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int ans = 0 ;
        vector<int> adj[n] ; 
        vector<int> vis(n , 0) ; 
        
        for(int i=0 ; i<n ; i++)
        {
            if(i != headID)
            {
                int man = manager[i] ; 
                adj[man].push_back(i) ;
            }
             
        }
        
        
        dfs(headID, informTime , adj) ;

        return mx ; 
    }
};