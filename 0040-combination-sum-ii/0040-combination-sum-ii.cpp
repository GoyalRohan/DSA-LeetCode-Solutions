class Solution {
public:
    
    void solve(int ind, vector<int>& candidates, int target, vector<int> &output, vector<vector<int>> &ans)
    {
        if(0 == target)
        {
            ans.push_back(output) ; 
            return ; 
        }
    
        
        for(int i=ind ; i<candidates.size() ; i++)
        {
            if(i > ind && candidates[i] == candidates[i-1])
                continue ; 
            
            if(target < candidates[ind])
                break ; 
            
            output.push_back(candidates[i]) ; 
            solve(i+1 , candidates , target - candidates[i] , output, ans) ; 
            output.pop_back() ; 
                
        }   
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> output ; 
        vector<vector<int>> ans ; 
        sort(candidates.begin(), candidates.end()) ; 
        
        solve(0 , candidates , target ,  output, ans) ; 
        return ans ; 
    }
};