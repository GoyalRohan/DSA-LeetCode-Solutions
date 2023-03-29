class Solution {
public:
    
    int solve(int i, int count , vector<int>& satisfaction , vector<vector<int>> &dp)
    {
        if(i == satisfaction.size())   
        {
            return 0 ; 
        }
        
        if(dp[i][count] != -1)
            return dp[i][count] ; 
        
        int notTake = 0 + solve(i+1, count, satisfaction , dp) ; 
        
        int take = satisfaction[i] * count + solve(i+1 , count+1 , satisfaction , dp) ;
        
        return dp[i][count] = max(take, notTake) ; 
        
    }
    
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size() ; 
        vector<vector<int>> dp(n+1 , vector<int>(n+1 , -1)) ; 
        sort(satisfaction.begin() , satisfaction.end()) ; 
        return max(0 , solve(0 , 1 , satisfaction , dp)) ; 
    }
};