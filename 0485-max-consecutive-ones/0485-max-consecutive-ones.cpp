class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size() ; 
        int last = -1 ; 
        int maxlen = 0 , len = 0 ; 
        
        for(int i=0 ; i<n ; i++)
        {
            if(last != -1 && last == nums[i])
            {
                len ++ ; 
                last = nums[i] ; 
                maxlen = max(maxlen , len) ; 
            }
            else if(nums[i] == 1)
            {
                len = 1 ; 
                last = nums[i] ; 
                maxlen = max(maxlen , len) ;
            }
            
            else
                len = 0 ; 
        }
        
        return maxlen ; 
        
    }
};