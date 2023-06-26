class Solution {
public:
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size() ; 
        vector<int> temp ; 
        temp.push_back(nums[0]) ;
        int maxi = 1 ; 
        
        for(int ind=1 ; ind<n ; ind++)
        {
            if(nums[ind] > temp.back())
            {
                temp.push_back(nums[ind]) ; 
                maxi++ ; 
            }
                
            else
            {
                int i = lower_bound(temp.begin(), temp.end() , nums[ind]) - temp.begin() ; 
                temp[i] = nums[ind] ; 
            }
        }
        
        
        return maxi ;
        // return dp[0][-1+1];
        // return solve(0 , -1 , nums , dp) ; 
    }
};