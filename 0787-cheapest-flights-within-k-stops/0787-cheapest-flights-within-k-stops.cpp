class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist1(n , 1e9) ; 
        dist1[src] = 0 ; 
        
        
        for(int i=1 ; i<=k+1 ; i++)
        {
            vector<int> dist2 = dist1 ; 
            for(auto edge : flights)
            {
                int u = edge[0] , v = edge[1] , wt = edge[2]; 
                if(dist1[u] + wt < dist2[v])
                    dist2[v] = dist1[u] + wt ; 

            }   
            
            dist1 = dist2 ; 
        }
        
        if(dist1[dst] == 1e9)
            return -1 ; 
        
        return dist1[dst] ; 
        
    }
};