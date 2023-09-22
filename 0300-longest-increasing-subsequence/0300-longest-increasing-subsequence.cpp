class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size() ; 
        vector<int> temp ; 
        temp.push_back(nums[0]) ; 
        int len = 1 ;
        
        for(int ind=1 ; ind<n ; ind++)
        {
            if(nums[ind] > temp.back())
            {
                temp.push_back(nums[ind]) ;
                len++ ; 
            }
            else
            {
                int index = lower_bound(temp.begin() , temp.end(), nums[ind]) - temp.begin() ; 
                temp[index] = nums[ind] ; 
            }
        }
        
        return len ; 
    }
};