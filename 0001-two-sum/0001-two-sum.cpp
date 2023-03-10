class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size() ; 
        vector<int > ans(2)  ; 
        unordered_map<int , int> mpp ;             
        
        for(int i=0 ; i<n ; i++)
        {
            int x = target - nums[i] ; 
            if(mpp.find(x) == mpp.end())
            {
                mpp[nums[i]] = i ; 
            }
            else
            {
                ans[0] = mpp[target - nums[i]] ; ans[1] = i ; 
                break ; 
            }
        }
        
        return ans ; 
    }
};