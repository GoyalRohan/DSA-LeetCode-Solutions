class Solution {
public:
    
//     int solve(int i, int j , vector<vector<int>>& vis, int n)
//     {
//         if(i<0 || j<0 || i>=n || j>=n)
//             return 1e8 ; 
        
//         if(vis[i][j] == 1 || vis[i][j] == -1)
//             return 0; 
        
//         vis[i][j] = -1 ; 
        
//         int ans = INT_MAX ; 
//         int first = 1 + solve(i-1 , j , vis , n) ;
//         int second = 1 + solve(i+1 , j , vis , n) ;
//         int third = 1 + solve(i , j-1 , vis , n) ;
//         int fourth = 1 + solve(i , j+1 , vis , n) ;
        
//         cout<<first<<"  "<<second<<"  "<<third<<"  "<<fourth<<endl ; 
//         ans = min(ans , min(first , min(second , min(third , fourth)))) ; 
        
//         vis[i][j] = 0 ; 
        
//         return ans ; 
        
//     }
    
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size() ; 
        queue<pair<int, int>> q ; 
        for(int i=0 ; i<n ; i++)
        {
            for(int j=0 ; j<n ; j++)
            {
                if(grid[i][j] == 1)
                {
                    q.push({i, j}) ; 
                }

            }
        }
        
        if(q.empty() || q.size() == n*n)
            return -1 ; 
        
        vector<int> dx = {0 , 0 , 1 , -1} ; 
        vector<int> dy = {1 , -1 , 0 , 0} ; 
         
        int ans = -1 ; 
        while(!q.empty())
        {
            int size = q.size() ; 
           ans++ ; 
            while(size-- > 0 )
            {
                int i = q.front().first , j = q.front().second ; 
                q.pop() ; 
                
                for(int k=0 ; k<4 ; k++)
                {
                    int row = i + dx[k] , col = j + dy[k] ; 
                    if(row >= 0 && col >= 0 && row <n && col<n && grid[row][col] == 0)
                    {
                        grid[row][col] = 1 ; 
                        q.push({row , col}) ; 
                    }
                }
                
            }
             
        }
        
        return ans ; 
    }
};