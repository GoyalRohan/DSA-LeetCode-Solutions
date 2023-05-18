class Solution {
public:
    
    int f(int ind , vector<int> &vec, vector<int> &dp)
    {
        if(ind == 0)
            return vec[0] ; 
        
        if(ind < 0)
            return INT_MIN ; 
        
        if(dp[ind] != -1)
            return dp[ind] ; 
        
        int take = vec[ind] ; 
        if(ind-2 >= 0)
         take +=  f(ind-2 , vec , dp) ; 
        int notTake = 0 + f(ind-1, vec, dp) ; 
        
        return dp[ind] = max(take, notTake) ; 
    }
    
    
    int houseRobber(vector<int> &vec)
    {
        int n = vec.size() ; 
        vector<int> dp(n , -1) ; 
        return f(n-1 , vec , dp) ; 
    }
    
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);
        
        // either use first house and can't use last or last and not first:
        
        vector<int> v1(nums.begin(), nums.end()-1);
        vector<int> v2(nums.begin()+1, nums.end());
        return max(houseRobber(v1), houseRobber(v2));
    }
};