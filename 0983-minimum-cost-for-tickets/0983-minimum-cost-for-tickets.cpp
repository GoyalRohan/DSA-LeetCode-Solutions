class Solution {
public:
    
    int solve(int i , int validDay , vector<int>& days, vector<int>& costs , vector<vector<int>> &dp)
    {
        if(i >= days.size())
            return 0 ; 
        
        if(dp[i][validDay] != -1)
            return dp[i][validDay] ; 
        
        if(days[i] > validDay)
        {
            int one = costs[0] + solve(i+1 , days[i] + 0 , days , costs , dp ) ; 
            int seven = costs[1] + solve(i+1 , days[i] + 6 , days ,costs , dp) ; 
            int thirty = costs[2] + solve(i+1 , days[i] + 29 , days , costs , dp) ; 
            
            int ans = min(one , seven) ; 
            ans = min(ans , thirty) ; 
            return dp[i][validDay] = ans ; 
            
        }
        else
            return dp[i][validDay] = 0 + solve(i+1 , validDay , days , costs, dp) ; 
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size() ; 
        vector<vector<int>> dp(n , vector<int>( 400 , -1)) ; 
        return solve(0 , 0 , days , costs , dp) ; 
    }
};