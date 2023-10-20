class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size() ; 
        int duplicate ; 
         
        for(int i=0 ; i<n ; i++)
        {
            if(nums[abs(nums[i]) - 1] > 0)
                nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1] ; 
            else
            {
                duplicate = abs(nums[i]) ; 
                break ; 
            }
        }
        
        return duplicate ; 
    }
};