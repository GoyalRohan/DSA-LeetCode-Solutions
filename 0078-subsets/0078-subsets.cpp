class Solution {
public:
    
    void solve(int ind , vector<int> &nums , vector<int> &output , vector<vector<int>> &ans)
    {
        if(ind == nums.size())
        {
            ans.push_back(output) ; 
            return ; 
        }
        
        solve(ind+1 , nums , output , ans) ; 
        output.push_back(nums[ind]) ; 
        solve(ind+1 , nums , output, ans) ; 
        output.pop_back() ; 
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans ; 
        vector<int> output ; 
        solve(0 , nums, output , ans) ; 
        return ans ; 
    }
};