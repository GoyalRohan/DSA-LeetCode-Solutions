class Solution {
public:
    
    int solve(int index ,vector<int>& days, vector<int>& costs , vector<int> &dp)
    {
        if(index >= days.size())
            return 0 ; 
        
        if(dp[index] != -1)
            return dp[index] ; 
        
        int one = costs[0] + solve(index+1 , days , costs , dp ) ; 
        
        int i; 
        
        for(i= index; i<days.size() && days[i] < days[index] + 7 ; i++) ; 
            
        int seven = costs[1] + solve(i, days ,costs , dp) ; 
        
        for(i= index; i<days.size() && days[i] < days[index] + 30 ; i++) ; 
            
        int thirty = costs[2] + solve(i, days ,costs , dp) ; 
        
        return dp[index] = min(one, min (seven, thirty)) ; 
        
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size() ; 
        vector<int> dp(n+1 , -1) ; 
        return solve(0 , days , costs , dp) ; 
    }
};