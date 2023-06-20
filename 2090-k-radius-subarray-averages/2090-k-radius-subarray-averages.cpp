class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size() ; 
        vector<int> ans(n , -1) ; 
        
        if(n < 2*k+1)
            return ans ; 
         
        long long sum = 0 ; 
        
        for(int i=0 ; i<2*k ; i++)
            sum = sum + nums[i] ; 
        
        for(int i=2*k ; i<n ; i++)
        {
            sum += nums[i] ; 
            int avg = sum /( 2*k + 1) ;
            
            ans[i-k] = avg ; 
            
            sum = sum - nums[i - 2*k] ; 
        }
        
        return ans ; 
    }
};