class Solution {
public:
    
    bool isPossible(int mid, int k, vector<int> &nums)
    {
        int sum = 0  , count = 1;
        
        for(int i=0 ; i<nums.size() ; i++)
        {
            if(sum + nums[i] <= mid)
            {
                sum += nums[i] ; 
            }
            else
            {
                count++ ; 
                if(count > k || nums[i] > mid)
                    return false ; 
                sum = nums[i] ; 
            }
            
        }
        
        return true ; 
        
    }
    
    int splitArray(vector<int>& nums, int k) {
        int totsum = 0 ; 
        for(auto n : nums)
            totsum += n ; 
        
        int low = 0  , high = totsum ; 
        int ans = -1 ; 
        
        while(low <= high)
        {
            // cout<<"Fsfd" ; 
            int mid = (low + high)/2 ; 
            if(isPossible(mid , k , nums))
            {
                ans = mid ; 
                // cout<<"fsfsfs"<<ans<<" " ; 
                high = mid-1 ; 
            }
            else
                low = mid+1 ; 
                
        }
        
        return ans ; 
        
    }
};