class Solution {
public:
    
    int solve(int ind, int target , vector<int> &nums, vector<vector<int>> &dp)
    {
        if(ind == 0)
        {
            if(target == 0 && nums[0] == 0)
                return 2; 
            if(target == 0 || nums[0] == target)
                return 1 ; 
            return 0 ; 
        }
        
        if(dp[ind][target] != -1)
            return dp[ind][target] ; 
        
        int pick = 0 , notpick = 0 ; 
        if(target >= nums[ind])
            pick = solve(ind-1 , target-nums[ind] , nums, dp) ; 
        
        notpick = solve(ind-1 , target , nums, dp) ; 
        
        return dp[ind][target] = pick + notpick ; 
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size(); 
        int totsum = 0 ; 
        
        for(auto nu : nums)
            totsum += nu ; 
        
        if(totsum - target < 0 || (totsum-target) % 2)
            return 0 ; 
        
        int tar = (totsum-target)/2 ; 
        
        vector<vector<int>> dp(n , vector<int>(tar+1 , -1)) ; 
        return solve(n-1 , tar , nums , dp) ; 
    }
};