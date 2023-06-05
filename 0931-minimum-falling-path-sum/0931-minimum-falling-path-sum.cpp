class Solution {
public:
    
    int solve(int i, int j , vector<vector<int>>& matrix , vector<vector<int>> &dp)
    {
        if(i<0 || j<0 || i>= matrix.size() || j>= matrix.size())
            return 1e8 ; 
        
        if(i == matrix.size() - 1)
            return matrix[i][j] ; 
        
        if(dp[i][j] != -1)
            return dp[i][j] ; 
        
        int rd = matrix[i][j] + solve(i+1 , j+1 , matrix , dp) ; 
        int ld = matrix[i][j] + solve(i+1 , j-1 , matrix , dp) ; 
        int d = matrix[i][j] + solve(i+1 , j , matrix , dp) ; 
        
        return dp[i][j] = min(rd , min(ld , d)) ; 
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size() ; 
        int mini = INT_MAX ; 
        vector<vector<int>> dp(n , vector<int>(n , 0)) ; 
    
        
        for(int j=0 ; j<n ; j++)
        {
            dp[n-1][j] = matrix[n-1][j] ; 
        }
        

            for(int i=n-2 ; i>=0 ; i--)
            {
                for(int j=0 ; j<n ; j++)
                {
                    int rd = matrix[i][j] , ld = matrix[i][j] , d = matrix[i][j] ; 
                    if(j+1 < n)
                        rd += dp[i+1][j+1] ; 
                    else
                        rd += 1e8 ; 
                    if(j > 0)
                        ld += dp[i+1][j-1] ; 
                    else
                        ld += 1e8 ; 
                    
                    
                    d += dp[i+1][j] ; 

                    dp[i][j] = min(rd , min(ld , d)) ; 
                }
            }
        
         for(int j=0 ; j<n ; j++)
        {
            mini = min(mini , dp[0][j]) ; 
        }
        
        
        return mini ; 
    }
};