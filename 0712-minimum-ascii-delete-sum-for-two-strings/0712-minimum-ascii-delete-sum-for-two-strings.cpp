class Solution {
public:
    
    // MEMOIZATION CODE
//     int solve(int i , int j , string s1 , string s2, vector<vector<int>> &dp)
//     {
//         if(i<0 && j<0)
//             return 0 ; 
        
//         if(i<0)
//         {
//             int sum = 0 ; 
//             while(j >= 0)
//             {
//                 sum += s2[j] ;
//                 j-- ; 
//             }
            
//             return sum ; 
//         }
        
//         if(j<0)
//         {
//             int sum = 0 ; 
//             while(i >= 0)
//             {
//                 sum += s1[i] ;
//                 i-- ; 
//             }
            
//             return sum ; 
//         }
        
//         if(dp[i][j] != -1)
//             return dp[i][j] ; 
        
//         if(s1[i] == s2[j])
//             return 0 + solve(i-1 , j-1 , s1 , s2, dp) ; 
        
//         int mini = min(s1[i] + solve(i-1, j , s1 , s2, dp)  ,  s2[j] + solve(i , j-1 , s1 , s2, dp)) ; 
        
//         return dp[i][j] = mini ; 
//     }
    
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size() , m = s2.size() ; 
        vector<vector<int>> dp(n+2 , vector<int>(m+2 , 0)) ; 
        
        int sum = 0 ; 
        for(int i=0 ; i<n ; i++)
        {
            sum += s1[i] ; 
            dp[i+1][0] = sum ; 
        }
        
        sum = 0 ; 
        for(int j=0 ; j<m ; j++)
        {
            sum += s2[j] ; 
            dp[0][j+1] = sum ; 
        }
        
        for(int i=1 ; i<=n ; i++)
        {
            for(int j=1 ; j<=m ; j++)
            {
                if(s1[i-1] == s2[j-1])
                    dp[i][j] = 0 + dp[i-1][j-1]  ;
                else
                    dp[i][j] = min(s1[i-1] + dp[i-1][j]   ,  s2[j-1] + dp[i][j-1]) ;                  
            }
        }
        
        return dp[n][m] ; 
        
        // return solve(n-1 , m-1 , s1 , s2 , dp) ; 
    }
};