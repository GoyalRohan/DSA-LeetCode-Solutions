class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size() , n = grid[0].size() ; 
        queue<pair<int, int>> q ; 
        int zeros = 0 ; 
        
        for(int i=0 ; i<m ; i++)
        {
            for(int j=0 ; j<n ; j++)
            {
                if(grid[i][j] == 2)
                    q.push({i,j}) ; 
                else if(grid[i][j] == 0)
                    zeros++ ; 
            }
        }
        
        if(zeros == m*n)
            return 0 ; 

        int dx[4] = {0 , 0 , 1 , -1} ; 
        int dy[4] = {1 , -1 , 0 , 0} ; 
        
        int dist = 0 ; 
        while(!q.empty())
        {
            int size= q.size() ; 
            while(size-- > 0)
            {
                int i = q.front().first , j = q.front().second ; 
                q.pop(); 
                
                for(int k=0 ; k<4 ; k++)
                {
                    int newi = i + dx[k] , newj = j+ dy[k] ; 
                    if(newi>=0 && newi<m && newj>=0 && newj<n && grid[newi][newj] == 1)
                    {
                        grid[newi][newj] = 2 ; 
                        q.push({newi, newj}) ; 
                    }
                } 
            }
            
            dist++ ; 
        }
        
        for(int i=0 ; i<m ; i++)
        {
            for(int j=0 ; j<n ; j++)
            {
                if(grid[i][j] == 1)
                    return -1 ; 
            }
        }
        
        return dist-1 ; 
    }
};