class Solution {
public:
    

    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size(); 
        int totsum = 0 ; 
        
        for(auto nu : nums)
            totsum += nu ; 
        
        if(totsum - target < 0 || (totsum-target) % 2)
            return 0 ; 
        
        int tar = (totsum-target)/2 ; 
        
        vector<vector<int>> dp(n+1 , vector<int>(tar+1 , 0)) ; 
        
        if(nums[0] == 0)
            dp[0][0] = 2 ; 
        else
            dp[0][0] = 1 ; 
        
        if(nums[0] != 0 && nums[0] <= tar)
            dp[0][nums[0]] = 1 ; 
        
        for(int ind = 1 ; ind<n ; ind++)
        {
            for(int target = 0 ; target <= tar ; target++)
            {
                int pick = 0 , notpick = 0 ; 
                if(target >= nums[ind])
                    pick = dp[ind-1][target-nums[ind]] ; 

                notpick = dp[ind-1][target] ;  

                dp[ind][target] = pick + notpick ; 
            }
        }
        
        return dp[n-1][tar] ; 
    }
};