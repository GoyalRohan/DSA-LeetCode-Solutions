class Solution {
public:
    
    int solve(int i, int j, int m, int n, vector<vector<int>>& matrix, int prev, vector<vector<int>> &dp)
    {
        if(i<0 || j<0 || i>=m ||  j>=n)
            return 0 ; 
        if(matrix[i][j] == -1 || matrix[i][j] <= prev)
            return 0 ; 
        
        if(dp[i][j] != -1)
            return dp[i][j] ; 
        
        int maxi = INT_MIN ; 
        int temp = matrix[i][j] ;
        matrix[i][j] = -1 ; 
        int step1 = 0 , step2 = 0 , step3 = 0 , step4 = 0 ; 
        
        step1 = 1 + solve(i-1 , j , m , n , matrix , temp , dp) ; 
        step2 = 1 + solve(i+1 , j , m , n , matrix , temp, dp) ; 
        step3 = 1 + solve(i , j-1 , m , n , matrix , temp, dp) ; 
        step4 = 1 + solve(i , j+1 , m , n , matrix , temp, dp) ; 
        
        maxi = max(maxi , max(step1 , max(step2 , max(step3 , step4)))) ; 
        
        matrix[i][j]  = temp ; 
        return dp[i][j] = maxi ; 
        
        
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size() , n = matrix[0].size() ; 
        vector<vector<int>> dp(m, vector<int>(n , -1)) ; 
        
        int maxi = 1 ; 
        for(int i=0 ; i<m ; i++)
        {
            for(int j=0 ; j<n ; j++)
            {
                maxi = max(maxi , solve(i , j , m , n , matrix , -1 , dp)) ; 
            }
        }
        
        return maxi ; 
    }
};