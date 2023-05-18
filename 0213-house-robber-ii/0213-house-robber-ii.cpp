class Solution {
public:    
    
    int houseRobber(vector<int> &vec)
    {
        int n = vec.size() ; 
        vector<int> dp(n , 0) ; 
        
        dp[0] = vec[0] ; 
        for(int ind=1 ; ind<n ; ind++)
        {
            int take = vec[ind] ; 
            if(ind-2 >= 0)
             take +=  dp[ind-2] ; 
            int notTake = 0 + dp[ind-1] ; 

            dp[ind] = max(take, notTake) ; 
        }
        
        
        
        return dp[n-1]; 
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