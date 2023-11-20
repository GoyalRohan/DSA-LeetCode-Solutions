class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int len = 0  , maxlen = 0;
        
        for(int i=0 ; i<nums.size() ; i++)
        {
            if(nums[i] == 1)
            {
                len++ ; 
                maxlen = max(len , maxlen) ; 
            }
            else
                len = 0 ; 
        }
        
        return maxlen ; 
    }
};