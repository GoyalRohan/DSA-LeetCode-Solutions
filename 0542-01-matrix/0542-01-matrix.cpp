class Solution {
public:
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size() , n = mat[0].size() ; 
        
        vector<vector<int>> dist(m, vector<int>(n , 0)); 
        // vector<vector<int>> dist(m, vector<int>( vis, 0)); 
        queue<pair<pair<int, int> , int>> q ; 
        
        for(int i=0 ; i<m ; i++)
        {
            for(int j=0 ; j<n ; j++)
            {
                if(mat[i][j] == 0)
                {
                    q.push({{i , j} , 0}) ; 
                    dist[i][j] = 0 ; 
                }
                
            }
        }
        
        vector<int> dx = {0 , 0 , -1 , 1} ; 
        vector<int> dy = {-1 , 1 , 0 , 0} ;
        
        while(!q.empty())
        {
            int row = q.front().first.first ; 
            int col = q.front().first.second ; 
            int steps = q.front().second ; 
            q.pop() ;
            
            dist[row][col] = steps ; 
            
             
            
            for(int i=0 ; i<4 ; i++)
            {
                int nrow = row + dx[i] ; 
                int ncol = col + dy[i] ; 
                
                if(nrow >=0 && ncol >= 0 && nrow <m && ncol <n && mat[nrow][ncol] == 1)
                {
                    mat[nrow][ncol] = 0 ; 
                    q.push({{nrow , ncol} , steps+1}) ; 
                }
            }
        }
        
        return dist ; 
    }
};