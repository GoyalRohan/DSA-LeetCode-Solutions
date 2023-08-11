class Solution {
public:
    
    int solve(int ind , int amt,  vector<int>& coins, vector<vector<int>> &dp)
    {
        if(amt == 0)
            return 1 ; 
        
        if(ind == 0)
        {
            if(amt % coins[0] == 0)
                return 1 ; 
            return 0 ; 
        }
        
        if(dp[ind][amt] != -1)
            return dp[ind][amt] ; 
        
        int ans = 0 ; 
        
        if(amt >= coins[ind])
            ans += solve(ind , amt - coins[ind] , coins, dp) ; 
        
        ans += solve(ind-1 , amt , coins, dp) ; 
        
        return dp[ind][amt] = ans ; 
    }
    
    int change(int amount, vector<int>& coins) {
        int n = coins.size(); 
        vector<vector<int>> dp(n+1 , vector<int>(amount+2 , 0)) ; 
        
        for(int ind=0 ; ind<n ; ind++)
            dp[ind][0] = 1 ; 
        
        for(int amt=1 ; amt <= amount ; amt++)
        {
            if(amt % coins[0] == 0)
                dp[0][amt] = 1 ; 
             else
                 dp[0][amt] =0 ;    
        }
        
        for(int ind=1 ; ind<n ; ind++)
        {
            for(int amt=0 ; amt <= amount ; amt++)
            {
                int ans = 0 ; 
        
                if(amt >= coins[ind])
                    ans += dp[ind][amt - coins[ind]] ; 

                ans += dp[ind-1][amt] ;  
                
                dp[ind][amt] = ans ; 
            }
        }
        
        return dp[n-1][amount] ; 
        // return solve(n-1 , amount , coins, dp) ; 
    }
};