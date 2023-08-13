class Solution {
public:
    
    bool search(int i , vector<int> &nums , vector<int> &dp)
    {
        if(i == nums.size())
            return true ;
        
        if(dp[i] != -1)
            return dp[i] ; 
        
        if(i+1 < nums.size() && nums[i+1] == nums[i])
        {
            if(search(i+2 , nums , dp))
                return true ; 
            if(i+2 < nums.size() && nums[i+2] == nums[i])
            {
                if(search(i+3 , nums , dp))
                    return true ; 
            }
                
        }
        
        if(i+2 < nums.size() && (nums[i+1] - nums[i] == 1) && (nums[i+2] - nums[i] == 2))
        {
            if(search(i+3 , nums , dp))
                return true ; 
        }
        
        return dp[i] = false ; 
            
    }
    
    bool validPartition(vector<int>& nums) {
        int n = nums.size() ; 
        vector<int> dp(n , -1) ; 
        return search(0, nums , dp) ; 
    }
};