class Solution {
public:
    
    int minPairSum(vector<int>& nums) {
        int n= nums.size() ;
        int low = INT_MAX , high = INT_MIN ; 
        int ans = INT_MIN; 
        
        vector<int> freq(100001, 0) ;
        
        for(int i=0 ; i<n; i++)
        {
            low = min(low , nums[i]) ; 
            high = max(high , nums[i]) ; 
            freq[nums[i]]++ ;
        }
        
        while(low <= high)
        {
            if(freq[low] == 0)
                low++ ; 
            else if(freq[high] == 0)
                high-- ; 
            else
            {
                int cursum = low + high ; 
                ans = max(ans, cursum) ; 
                freq[low]-- ; freq[high]-- ; 
            }
        }
        
        return ans ; 
    }
};