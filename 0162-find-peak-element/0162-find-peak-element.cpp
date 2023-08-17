class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n= nums.size() ; 
        
        int low = 0 , high = n-1 ; 
        
        while(low <= high)
        {
            int mid = (low+high)/2 ; 
            if((mid==0 || nums[mid] >= nums[mid-1]) && (mid == n-1 || nums[mid+1] <=nums[mid]))
                return mid ; 
            else if(nums[mid+1] >= nums[mid])
                low = mid+1 ; 
            else
                high = mid-1 ; 
        }
        
        return -1 ; 
    }
};