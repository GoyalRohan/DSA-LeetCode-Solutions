class Solution {
public:
    
    int stoneGameII(vector<int>& piles) {
        int n = piles.size() ; 
        vector<int> suffixSum(n) ; 
        suffixSum[n-1] = piles[n-1] ; 
        
        for(int i=n-2 ; i>=0 ; i--)
            suffixSum[i] = piles[i] + suffixSum[i+1] ; 
        
        vector<vector<int>> dp(n+1 , vector<int>(n+1 , 0)) ; 
        
        for(int i=n-1 ; i>=0 ; i--)
        {
            for(int m=1 ; m<=n ; m++)
            {
                if(i + 2*m >= n)
                    dp[i][m] = suffixSum[i] ; 
                else
                {
                    int result = 0 ; 
                    for(int x=1 ; x <= 2*m ; x++)
                    {
                        result = max(result , suffixSum[i] - dp[i+x][max(x,m)]) ;
                    }

                    dp[i][m] = result; 
                }
            }
        }
        
        return dp[0][1] ; 
        // return helper(0 , 1 , piles , suffixSum , dp) ; 
    }
};