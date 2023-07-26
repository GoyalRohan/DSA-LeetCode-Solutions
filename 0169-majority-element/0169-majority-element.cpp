class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1 ; 
        int maj = nums[0] ; 
        
        for(int i=1 ; i<nums.size() ; i++)
        {
            if(nums[i] == maj)
                count++ ; 
            else
            {
                count-- ; 
                if(count == 0)
                {
                    count = 1 ; 
                    maj = nums[i] ; 
                }
            }
        }
        
        return maj ; 
    }
};