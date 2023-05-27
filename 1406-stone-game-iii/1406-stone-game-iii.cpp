class Solution {
public:
    
    int solve(int ind , vector<int>& stoneValue , vector<int> &dp ) 
    {
        int n = stoneValue.size() ; 
        if(ind >= n)
            return 0 ; 
        
        if(dp[ind] != -1)
            return dp[ind] ; 
        
        int one = stoneValue[ind] - solve(ind+1 , stoneValue , dp) ; 
            
        int two  = INT_MIN ; 
        if(ind+1 < n)
            two = stoneValue[ind] + stoneValue[ind+1] - solve(ind+2 , stoneValue , dp) ; 
        
        int three  = INT_MIN ; 
        if(ind+2 < n)
            three = stoneValue[ind] + stoneValue[ind+1] +  stoneValue[ind+2] - solve(ind+3 , stoneValue , dp) ; 
        
        
        return dp[ind] = max(one , max(two ,three)) ; 
    }
    
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size() ; 
        vector<int> dp(n , -1) ; 
        
        int value = solve(0 , stoneValue , dp) ; 
        if(value > 0)
            return "Alice" ; 
        else if(value<0)
            return "Bob" ; 
        return "Tie" ; 
    }
};