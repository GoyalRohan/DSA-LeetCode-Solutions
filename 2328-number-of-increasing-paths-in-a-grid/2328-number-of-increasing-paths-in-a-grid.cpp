class Solution {
public:
    int mod = 1e9 + 7 ; 
        
    int solve(int i, int j , int m , int n , int parent, vector<vector<int>> &dp,  vector<vector<int>>& grid)
    {
        if(i<0 || j<0 || i>=m || j>=n || parent >= grid[i][j])
            return 0 ; 
        
        if(dp[i][j] != -1)
            return dp[i][j] ; 
        
        int up = solve(i-1 , j , m , n , grid[i][j] , dp , grid) ; 
        int down = solve(i+1 , j , m , n , grid[i][j] , dp , grid) ; 
        int left = solve(i , j-1 , m , n , grid[i][j] , dp , grid) ; 
        int right = solve(i , j+1 , m , n , grid[i][j] , dp , grid) ; 
        
        return dp[i][j] = (up%mod + down%mod + left%mod + right%mod + 1) %mod ; 
        
    }
    
    int countPaths(vector<vector<int>>& grid) {
        int m = grid.size() , n = grid[0].size() ; 
        vector<vector<int>> dp(m , vector<int>(n , -1)) ;  
        
        for(int i=0 ; i<m ; i++)
        {
            for(int j=0 ; j<n ; j++)
            {
                if(dp[i][j] == -1)
                    solve(i , j , m , n , -1 , dp , grid) ; 
            }
        }
        
        long long ans = 0 ; 
        
        for(int i=0 ; i<m ; i++)
        {
            for(int j=0 ; j<n ; j++)
            {
                if(dp[i][j] == -1)
                    solve(i , j , m , n , -1 , grid , dp) ; 
            }
        }
        
        for(int i=0 ; i<m ; i++)
        {
            for(int j=0 ; j<n ; j++)
            {
                cout<<dp[i][j]<<" " ; 
                ans = (ans + dp[i][j])%mod ; 
            }
            cout<<endl ; 
        }
        
        return ans ; 
    }
};