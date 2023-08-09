class Solution {
public:
    
    bool isPossible(vector<int> &nums, int mid, int p, int n)
    {
        // cout<<mid<<endl; 
        unordered_set<int> myset ; 
        int count = 0 ; 
        // for(auto nu : nums)
        //     cout<<nu<<" " ; 
        // cout<<endl ; 
        for(int i=0 ; i<n-1 ; i++)
        {
            if(nums[i+1] - nums[i] <= mid)
            {
                if(myset.find(i) == myset.end() && myset.find(i+1) == myset.end())
                {
                    count++ ; 
                    myset.insert(i) ; 
                    myset.insert(i+1) ; 
                    // cout<<i<<" "<<i+1<<endl ; 
                    if(count >= p)
                        return true ; 
                }
            }
        }
        
        return false ;
    }
    
    int minimizeMax(vector<int>& nums, int p) {
        
        if(p == 0)
            return 0 ; 
        
        int n = nums.size() ; 
        sort(nums.begin() , nums.end()) ; 
        int low = INT_MAX , high = 0 ; 
       
        high = nums[n-1] - nums[0] ; 
        
        for(int i=0 ; i<n-1 ; i++)
        {
            low = min(low , nums[i+1] - nums[i]) ; 
        }
        
        int ans ; 
        while(low <= high)
        {
            int mid = (low + high)/2 ; 
            if(isPossible(nums , mid , p , n))
            {
                ans = mid ; 
                // cout<<mid<<" " <<endl; 
                high = mid - 1 ; 
            }
            else
                low = mid + 1 ; 
        }
        
        return ans ; 
    }
};