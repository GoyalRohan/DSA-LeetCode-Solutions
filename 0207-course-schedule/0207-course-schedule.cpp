class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<int> adj[n]; 
        
        for(auto edge : prerequisites)
        {
            int v = edge[0] , u = edge[1] ; 
            adj[u].push_back(v) ; 
        }
        
        vector<int> indegree(n , 0) ; 
        int cnt = 0 ;
        queue<int> q ; 
        
        for(int i=0 ; i<n ; i++)
        {
            for(auto it : adj[i])
            {
                indegree[it]++ ; 
            }
        }
        
        for(int i=0 ; i<n ; i++)
        {
            if(indegree[i] == 0)
                q.push(i) ; 
        }
        
        if(q.size() == 0)
            return false ; 
        
        while(!q.empty())
        {
            int node = q.front() ; q.pop() ; 
            cnt++ ; 
            for(auto it : adj[node])
            {
                indegree[it]-- ; 
                if(indegree[it] == 0)
                    q.push(it) ; 
            }
        }
        
        if(cnt == n)
            return true ; 
        
        return false ; 
    }
};