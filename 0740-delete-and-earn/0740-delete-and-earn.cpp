class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size() ; 
        int maxi = *max_element(nums.begin() , nums.end()) ; 
        int dp[200005] ; 
        vector<int> freq(200005 , 0) ; 
        
        for(auto nu : nums)
            freq[nu]++ ; 
        
        dp[1]= freq[1] ; 
        dp[2]= max(dp[1] , 2*freq[2]) ; 
        
        for(int i=3 ; i<=maxi ; i++)
        {
            dp[i] = max(dp[i-1] , dp[i-2] + i*freq[i]) ; 
        }
        
        return dp[maxi] ;
        
    }
};