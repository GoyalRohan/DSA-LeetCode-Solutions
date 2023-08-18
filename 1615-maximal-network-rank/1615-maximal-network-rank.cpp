class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        
        vector<int> adj(n) ; 
        unordered_map<int , unordered_set<int>> mpp ; 
        
        for(auto road : roads)
        {
            int u = road[0] , v= road[1] ; 
            mpp[u].insert(v) ; 
            mpp[v].insert(u) ; 
            // adj[u].push_back(v) ; 
            // adj[v].push_back(u) ; 
        }
        
        int maxi = 0 ; 
        for(int i=0 ; i<n ; i++)
        {
            for(int j=0 ; j<n ; j++)
            {
                if(i == j)
                    continue ; 
                
                int sum = mpp[i].size() + mpp[j].size() ; 
                
                if(mpp[i].count(j))
                    sum-- ;
                
                maxi = max(maxi , sum) ; 
            }
        }
        
        return maxi ; 
    }
};