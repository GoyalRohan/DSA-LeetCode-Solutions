class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n , INT_MAX) ;
        dist[src] = 0 ; 
        
        for(int i=1 ; i<=k+1 ; i++)
        {
            vector<int> tempdist = dist ; 
            for(auto flight : flights)
            {
                int u = flight[0] , v = flight[1] , cost = flight[2] ; 
                if(dist[u] != INT_MAX && dist[u] + cost < tempdist[v])
                    tempdist[v] = dist[u] + cost ; 
            }
            
            dist = tempdist ; 
        }
        
        if(dist[dst] != INT_MAX)
            return dist[dst] ;
        
        return -1 ; 
    }
};