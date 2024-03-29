class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size() ; 
        int i , j; 
        for(i=n-2 ; i>=0 ; i--)
        {
            if(nums[i+1] > nums[i])
            {
                break ; 
            }
        }
        
        if(i < 0)
        {
            sort(nums.begin(), nums.end()) ; 
            return ; 
        }
        else
        {
            for( j=n-1 ; j>i ; j--)
            {
                if(nums[j] > nums[i])
                    break ; 
            }
        }
        
        swap(nums[j] , nums[i]) ; 
        sort(nums.begin()+i+1 , nums.end()) ; 
    }
};