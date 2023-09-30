class Solution {
public:
    
    int solve(int i, vector<int> &nums, vector<int> &dp)
    {
        if(i == nums.size())
            return 0 ; 
        
        if(dp[i] != -1)
            return dp[i] ; 
        
        int curvalue = nums[i] ; 
        int cursum = nums[i] ; 
        int index = i+1 ; 
        while(index < nums.size() && curvalue == nums[index])
        {
            cursum += curvalue ; 
            index++ ; 
        }
        
        while(index < nums.size() && curvalue + 1 == nums[index])
        {
            index++ ; 
        }
        
        return dp[i] = max(cursum + solve(index , nums , dp) , solve(i+1 , nums , dp)) ; 
        
    }
    
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size() ; 
        sort(nums.begin() , nums.end()) ; 
        
        vector<int> dp(n , -1) ; 
        return solve(0 , nums , dp) ; 
    }
};