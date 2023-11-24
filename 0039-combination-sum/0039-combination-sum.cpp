class Solution {
public:
    
    vector<vector<int>> ans ; 
    
    void solve(int ind , vector<int> &output , int target , vector<int>& candidates)
    {
        if(target == 0)
        {
            ans.push_back(output) ; 
            return ; 
        }
        
        for(int i=ind ; i<candidates.size() ; i++)
        {
            if(candidates[i] > target)
                break ; 
            
            output.push_back(candidates[i]) ; 
            solve(i , output , target-candidates[i], candidates) ; 
            output.pop_back() ; 
            
        }
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin() , candidates.end()) ; 
        vector<int> output ; 
        solve(0 , output, target , candidates) ; 
        return ans ; 
    }
};