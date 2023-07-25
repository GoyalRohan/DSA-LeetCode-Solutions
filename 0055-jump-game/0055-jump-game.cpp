class Solution {
public:
    
    bool solve(int i, vector<int> &nums, vector<int> &dp)
    {
        
        if(i >= nums.size() - 1)
        {
            // cout<<i<<" " ; 
            return true ; 
        }
            
        if(dp[i] != -1)
            return dp[i] ; 
        
        int maxJump = nums[i] ; 
        // cout<<i<<" "<<maxJump<<endl ; 
        
        if(maxJump == 0)
            return  dp[i] = false ; 
        
        for(int ind=1 ; ind<=maxJump ; ind++)
        {
            if(solve(i+ind , nums, dp))
            {
                // cout<<i<<" + "<<ind<<endl ; 
                return  dp[i] = true ;
            }
                 
        }
        
        return  dp[i] = false ; 

    }
    
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size() , -1) ; 
        return solve(0 , nums, dp) ; 
    }
};