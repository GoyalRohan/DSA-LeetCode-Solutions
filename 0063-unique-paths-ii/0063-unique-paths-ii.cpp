class Solution {
public:
    
    int solve(int i, int j , int n , int m , vector<vector<int>>& obstacleGrid , vector<vector<int>> &dp)
    {
        if(i <0 || j<0 || i>=n || j>=m || obstacleGrid[i][j] == 1)
            return 0  ;
        
        if(i==0 && j == 0)
            return 1 ; 
        
        if(dp[i][j] != -1)
            return dp[i][j] ; 
        
        int down = solve(i-1 , j , n , m , obstacleGrid , dp) ;
        int right = solve(i , j-1 , n , m , obstacleGrid, dp) ;
        
        return dp[i][j] = down + right ; 
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size() , m = obstacleGrid[0].size() ; 
        vector<vector<int>> dp(n , vector<int>(m , 0)) ; 
        
        // if(n== 1 && )
        
        for(int i=0 ; i<n ; i++)
        {
            for(int j=0 ; j<m ; j++)
            { 
                if(obstacleGrid[i][j] == 1)
                    dp[i][j] = 0 ; 
                
                else if(i==0 && j== 0)
                    dp[i][j] = 1 ; 
                else
                {
                    int down = 0 , right= 0 ; 
                    
                    if(i > 0)
                        down = dp[i-1][j] ; 
                    if(j > 0)
                        right = dp[i][j-1] ; 
                    
                    dp[i][j] = down + right ;
                }
                
            }
        }
        
        return dp[n-1][m-1] ; 
        
        // return solve(n-1 , m-1 , n , m , obstacleGrid , dp) ; 
    }
};