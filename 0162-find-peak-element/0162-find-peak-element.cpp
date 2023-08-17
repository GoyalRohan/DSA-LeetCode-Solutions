class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size() ; 
        int prev = INT_MIN , next = INT_MIN ; 
        
        if(n==1)
            return 0 ; 
        
        for(int i=0 ; i<n ; i++)
        {
            if(i==n-1)
                next = INT_MIN ; 
            else
                next = nums[i+1] ; 
            
            if(nums[i] > prev && nums[i]>next)
                return i ; 
            
            prev = nums[i] ; 
        }
        
        return -1 ; 
    }
};