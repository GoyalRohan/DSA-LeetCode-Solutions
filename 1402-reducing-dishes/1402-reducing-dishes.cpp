class Solution {
public:
    
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size() ; 
        vector<vector<int>> dp(n+1 , vector<int>(n+2 , 0)) ; 
        sort(satisfaction.begin() , satisfaction.end()) ; 
        int maxi = 0 ; 
        
        
        for(int i=n-1 ; i>=0 ; i--)
        {
            for(int count=i+1 ; count>=1 ; count--)
            {
                int notTake = 0 + dp[i+1][count-1] ; 
        
                int take = satisfaction[i] * count + dp[i+1][count] ;
                dp[i][count-1] = max(take, notTake) ; 
                
            }
        }
        
        
        return dp[0][0] ;
    }
};