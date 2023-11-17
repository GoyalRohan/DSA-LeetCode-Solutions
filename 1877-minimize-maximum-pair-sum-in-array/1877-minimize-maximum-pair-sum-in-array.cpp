class Solution {
public:
    
    int minPairSum(vector<int>& nums) {
        int n= nums.size() ;
        int low = 0 , high = n-1 ; 
        int ans = INT_MIN; 
        sort(nums.begin(), nums.end()) ; 
        
        while(low < high)
        {
            int cursum = nums[low] + nums[high] ; 
            if(ans < cursum)
                ans = cursum ; 
            low++ ; high-- ; 
        }
        
        return ans ; 
    }
};