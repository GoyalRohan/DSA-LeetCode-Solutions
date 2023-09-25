class Solution {
public:
    
    double champagneTower(int poured, int query_row, int query_glass) {
        int n=100 ; 
        vector<vector<double>> dp(n+1 , vector<double>(n+1 , 0)) ; 
        // return min(1.0 , solve(poured, query_row, query_glass , dp) );
        
        dp[0][0] = poured ;
        
        for(int i=0 ; i<= query_row ; i++)
        {
            for(int j=0 ; j<=i ; j++)
            {
                double remaining = max(dp[i][j] - 1.0 , 0.0) ; 
                dp[i+1][j] += remaining/2.0 ; 
                dp[i+1][j+1] += remaining/2.0 ; 
            }
        }
        
        
        return min(1.0 , dp[query_row][query_glass]) ; 
        
    }
};