class Solution {
public:
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size() ; 
        vector<vector<int>> dp(n+1 , vector<int>( 400 , 0)) ; 
        
        for(int i=n-1 ; i>=0 ; i--)
        {
            for(int validDay= 0 ; validDay <= days[i]+29 ; validDay++ )
            {
                if(days[i] > validDay)
                {
                    int one = costs[0] + dp[i+1][days[i] + 0] ; 
                    int seven = costs[1] + dp[i+1][days[i] + 6] ; 
                    int thirty = costs[2] + dp[i+1][days[i] + 29] ; 

                    int ans = min(one , seven) ; 
                    ans = min(ans , thirty) ; 
                    dp[i][validDay] = ans ; 

                }
                else
                    dp[i][validDay] = 0 + dp[i+1][validDay] ;
            }
        }
        
        
        return dp[0][0] ; 
    }
};