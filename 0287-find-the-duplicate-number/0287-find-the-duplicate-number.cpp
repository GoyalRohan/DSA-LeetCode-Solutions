class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size() ; int duplicate = 0 ; 
        for(int i=0 ; i<n ; i++)
        {
            if(nums[abs(nums[i]) - 1] > 0)
            {
                nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1] ; 
            }
            else 
                duplicate = abs(nums[i]) ;
        }
        
        return duplicate; 
    }
};