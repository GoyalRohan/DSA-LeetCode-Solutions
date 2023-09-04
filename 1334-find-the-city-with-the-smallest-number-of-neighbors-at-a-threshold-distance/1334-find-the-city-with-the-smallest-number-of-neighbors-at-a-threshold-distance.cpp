class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n , vector<int>(n , 1e9)) ; 
        for(int i=0 ; i<n ; i++)
        {
            for(int j=0 ; j<n ; j++)
            {
                if(i == j)
                    dist[i][j] = 0 ; 
            }
        }
        
        for(auto edge : edges)
        {
            int u = edge[0] , v = edge[1] , wt = edge[2] ; 
            dist[u][v] = wt ; dist[v][u] = wt ; 
        }
        
        for(int k=0 ; k<n ; k++)
        {
            for(int i=0; i<n ; i++)
            {
                for(int j=0 ; j<n ; j++)
                {
                    if( dist[i][k] != 1e9 && dist[k][j] != 1e9 &&  dist[i][k] + dist[k][j] < dist[i][j] )
                        dist[i][j] = dist[i][k] + dist[k][j]  ; 
                }
            }
        }
        
        
        int anscity = -1 , mini = n ; 
        
        for(int i=0 ; i<n ; i++)
        {
            int cnt = 0 ; 
            for(int j=0 ; j<n ; j++)
            {
                if(i == j)
                    continue ; 
                if(dist[i][j] <= distanceThreshold)
                    cnt++ ; 
            }
            
            if(cnt <= mini)
            {
                anscity = i ; 
                mini = cnt ; 
            }
        }
        
        return anscity ; 
    }
};