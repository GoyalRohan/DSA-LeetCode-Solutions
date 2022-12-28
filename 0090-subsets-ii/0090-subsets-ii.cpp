class Solution {
public:
    
    void solve(int ind , vector<int> &output , vector<int>& nums , vector<vector<int>> &result)
    {
        if(ind == nums.size())
        {
            result.push_back(output) ; 
            return ; 
        }
        
        output.push_back(nums[ind]) ; 
        solve(ind+1 , output , nums, result) ; 
        output.pop_back() ; 
        
        while(ind+1 < nums.size() && nums[ind] == nums[ind+1])
            ind++ ; 
        solve(ind+1 , output, nums, result) ; 
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result ; 
        vector<int> output ; 
        
        sort(nums.begin() , nums.end()) ; 
        solve(0 , output , nums , result) ;
        return result ;
    }
};