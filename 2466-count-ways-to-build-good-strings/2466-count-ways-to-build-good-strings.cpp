class Solution {
public:
    int mod = 1e9 + 7 ; 
    
    int solve(int target, int zero, int one, vector<int> &dp)
    {
        if(target == 0)
            return 1 ; 
        
        if(target < 0)
            return 0 ;
        
        if(dp[target] != -1)
            return dp[target] ; 
        
        int first = (solve(target - zero, zero, one, dp))%mod ; 
        int second = (solve(target - one, zero, one, dp))%mod ; 
        
        return dp[target] = (first + second)%mod ; 
    }
    
    int countGoodStrings(int low, int high, int zero, int one) {
        
        long long sum = 0 ; 
        vector<int> dp(high+1 , -1) ; 
        
        for(int i=low ; i<=high ; i++)
        {
            sum += solve(i , zero, one , dp)%mod ; 
        }
        
        return sum%mod ; 
    }
};