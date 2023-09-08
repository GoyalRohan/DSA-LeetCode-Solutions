class Solution {
public:
    
    int solve(int ind , int n, vector<int>& nums, vector<int> &dp)
    {
        if(ind >= n)
            return 0 ; 
        
        if(dp[ind] != -1)
            return dp[ind] ; 
        
        int pick = nums[ind] + solve(ind+2 , n , nums, dp) ; 
        int notpick = 0 + solve(ind+1 , n , nums, dp) ; 
        
        return dp[ind] = max(pick , notpick) ; 
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size() ; 
        vector<int> dp(n , -1) ; 
        return solve(0 , n , nums , dp) ; 
    }
};