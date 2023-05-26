class Solution {
public:
    
    
    int helper(int ind , int m , vector<int>& piles , vector<int> &suffixSum , vector<vector<int>> &dp)
    {
        if(ind >= piles.size())
            return 0 ;
                
        if(ind + 2*m >= piles.size())
             return suffixSum[ind] ; 
        
        if(dp[ind][m] != -1)
            return dp[ind][m] ; 
        
        int result = 0 ; 
        for(int x=1 ; x <= 2*m ; x++)
        {
            result = max(result , suffixSum[ind] - helper(ind + x , max(x , m) , piles , suffixSum , dp)) ; 
        }
        
        return dp[ind][m] = result; 
            
    }
    
    int stoneGameII(vector<int>& piles) {
        int n = piles.size() ; 
        vector<int> suffixSum(n) ; 
        suffixSum[n-1] = piles[n-1] ; 
        
        for(int i=n-2 ; i>=0 ; i--)
            suffixSum[i] = piles[i] + suffixSum[i+1] ; 
        
        vector<vector<int>> dp(n , vector<int>(n , -1)) ; 
        
        return helper(0 , 1 , piles , suffixSum , dp) ; 
    }
};