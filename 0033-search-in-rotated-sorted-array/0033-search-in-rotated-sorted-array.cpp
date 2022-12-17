class Solution {
public:
    
    int bsearch(int s , int e , int target, vector<int>& nums)
    {
        if(s > e)
            return -1 ; 
        
        int mid = (s+ e)/2 ; 
        
        if(target == nums[mid])
            return mid ; 
        
        if(nums[s] <= nums[mid])
        {
            if(target >= nums[s] && target <= nums[mid])
                return bsearch(s , mid-1 , target, nums) ; 
            else
                return bsearch(mid+1 , e , target , nums) ; 
        }
        
        else if(target >= nums[mid] && target <= nums[e])
            return bsearch(mid+1 , e , target, nums) ; 
        
        else return bsearch(s , mid-1 , target , nums) ; 
    }
    
    int search(vector<int>& nums, int target) {
        int n = nums.size() ; 
        int s = 0 , e = nums.size() - 1 ; 
        
        return bsearch(s , e , target , nums) ; 
    }
};