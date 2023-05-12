class Solution {
public:
    
    long long solve(long long ind, vector<vector<int>>& questions, int n, vector<long long> &dp)
    {
        if(ind >= n)   
            return 0 ; 
        
        if(dp[ind] != -1)
            return dp[ind] ; 
                
        long long include = questions[ind][0] + solve(ind + questions[ind][1] + 1 , questions, n, dp);
        long long exclude = 0 + solve(ind+1, questions, n, dp) ; 
        
        return dp[ind] = max(include, exclude) ; 
    }
    
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size() ; 
        vector<long long> dp(n, -1 ) ; 
        return solve(0 , questions, n , dp) ; 
    }
};