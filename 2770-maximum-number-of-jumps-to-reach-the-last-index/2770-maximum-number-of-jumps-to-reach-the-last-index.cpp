class Solution {
public:
    
//     int solve(int i, int target, vector<int> &nums , int n, vector<int> &dp)
//     {
//         if(i >= n) return -1e9 ; 
//         if(i == n-1)
//             return 0 ;
        
//         if(dp[i] != -1)
//             return dp[i] ; 
        
//         int maxi = -1e9 ; 
//         for(int j=i+1 ; j<n ; j++)
//         {
//             if(abs(nums[j] - nums[i]) <= target)
//                 maxi = max(maxi , 1 + solve(j , target , nums, n, dp)) ; 
//         } 
        
//         return dp[i] = maxi ; 
//     }
    
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size() ; 
        vector<int> dp(n , 0) ; 
        
        for(int i=n-2 ; i >=0 ; i--)
        {
            int maxi = -1e9 ; 
            for(int j=i+1 ; j<n ; j++)
            {
                if(abs(nums[j] - nums[i]) <= target)
                    maxi = max(maxi , 1 + dp[j]) ; 
            } 

            dp[i] = maxi ; 
        }
        
        int ans = dp[0] ; 
        if(ans <= -1e8)
            return -1 ; 
        return ans ; 
    }
};