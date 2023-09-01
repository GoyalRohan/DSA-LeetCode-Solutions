class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> adj[n] ; 
        
        for(int i=0 ; i<n ; i++)
        {
            // cout<<manager[i]<<" " ; 
            if(manager[i] != -1)
                adj[manager[i]].push_back(i) ; 
        }
            
        // for(int i=0; i<n ; i++)
        // {
        //     cout<<i <<":"; 
        //     for(auto e : adj[i])
        //         cout<<e<<" " ; 
        //     cout<<endl ; 
        // }
        
        queue<pair<int, int>> q ; 
        q.push({headID , 0}) ; 
        int ans = 0 ; 
        
        while(!q.empty())
        {
            
                int emp = q.front().first , val = q.front().second; 
                q.pop() ; 

                for(int it : adj[emp])
                {
                    q.push({it , informTime[emp] + val}) ; 
                    ans = max(ans , informTime[emp] + val) ; 
                }
            
        }
        
        return ans ; 
        
    }
};