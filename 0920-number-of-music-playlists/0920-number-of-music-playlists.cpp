class Solution {
public:
    
    int mod = 1e9 + 7 ; 
    
    long long solve(long long songs , long long unique , long long n, long long goal, long long k , vector<vector<long long>> &dp)
    {
        if(songs == goal)
        {
            if(unique == n)
              return 1 ; 
            return 0 ; 
        }
        
        if(dp[songs][unique] != -1)
            return dp[songs][unique] ; 
        
        long long ans = 0 ; 
        if(n > unique)
            ans  += ((n-unique) * (solve(songs+1 , unique+1 , n , goal , k , dp))%mod)%mod ; 
        
        if(unique > k)
            ans += ((unique-k) * (solve(songs+1 , unique , n , goal , k , dp))%mod)%mod ; 
        
        return dp[songs][unique] = ans ; 
    }
    
    int numMusicPlaylists(int n, int goal, int k) {
        vector<vector<long long>> dp(goal , vector<long long>(goal , -1)) ; 
        return solve(0 , 0 , n ,goal, k, dp) ; 
    }
};