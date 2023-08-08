class Solution {
public:
    
    int findPivot(int start , int end , vector<int>& nums)
    {
        while(start <= end)
        {
            int mid = start + (end-start)/2 ; 
            if(mid < end && nums[mid] > nums[mid+1])
                return mid ; 
            if(mid > start && nums[mid-1] > nums[mid])
                return mid-1 ; 
            
                
            if(nums[start] >= nums[mid])
                end = mid-1 ; 
            else
                start = mid+1 ; 
        }
        return -1 ; 
        
    }
    
    int Bsearch(int start , int end , vector<int> &nums , int target)
    {
        while(start <= end)
        {
            int mid = start + (end-start)/2 ;
            if(target == nums[mid])
                return mid ; 
            else if(target > nums[mid])
                start = mid+1 ; 
            else 
                end = mid-1 ; 
        }
        return -1 ; 
    }
    
    
    int search(vector<int>& nums, int target) {
        int n = nums.size()  ; 
        
        
        int pivot = findPivot(0 , n-1 , nums) ; 
        
        if(pivot == -1)
            return Bsearch(0 , n-1 , nums , target) ; 
        
        if(target == nums[pivot] )
            return pivot ; 
         if(target >= nums[0] )
             return Bsearch(0 , pivot-1 , nums , target) ; 
        
            return Bsearch(pivot+1 , n-1 , nums , target) ; 
        
    }
};