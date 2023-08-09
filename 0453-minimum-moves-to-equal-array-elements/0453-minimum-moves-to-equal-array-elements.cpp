class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();  
        int mini = INT_MAX ; 
        
        for(int i=0 ; i<n ; i++)
            mini = min(mini, nums[i]) ; 
        
        int ans = 0 ; 
        for(auto nu : nums)
            ans += nu - mini ; 
        
        return ans ; 
    }
};