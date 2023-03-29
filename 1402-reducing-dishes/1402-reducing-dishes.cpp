class Solution {
public:
    
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size() ; 
        vector<vector<int>> dp(n+1 , vector<int>(n+2 , 0)) ; 
        sort(satisfaction.begin() , satisfaction.end()) ; 

        
        for(int i=n-1 ; i>=0 ; i--)
        {
            for(int count=i ; count>=0 ; count--)
            {
                int notTake = 0 + dp[i+1][count] ; 
        
                int take = satisfaction[i] * (count+1) + dp[i+1][count+1] ;
                dp[i][count] = max(take, notTake) ; 
                
            }
        }
        
        
        return dp[0][0] ;
    }
};