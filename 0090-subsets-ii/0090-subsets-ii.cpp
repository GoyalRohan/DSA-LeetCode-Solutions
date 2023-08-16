class Solution {
public:
    
    void solve(int ind, vector<int> &nums, int n , vector<int> &output , vector<vector<int>> &ans)
    {
        if(ind == n)
        {
            ans.push_back(output) ; 
            return ; 
        }
        
        output.push_back(nums[ind]) ; 
        solve(ind+1 , nums, n , output , ans) ;
        output.pop_back() ; 
        
        
        while(ind <n-1 && nums[ind+1] == nums[ind])
            ind++ ;
        solve(ind+1 , nums, n , output , ans) ; 
        
         
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans ; 
        vector<int> output ; 
        int n = nums.size() ; 
        sort(nums.begin() , nums.end()) ;
        solve(0 , nums , n , output , ans) ; 
        return ans ; 
    }
};