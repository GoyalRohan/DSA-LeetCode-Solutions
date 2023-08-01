class Solution {
public:
    
    void solve(int i, int k, int n, vector<vector<int>> &ans, vector<int> temp)
    { 
        if(k==0)
        {
            ans.push_back(temp) ; 
            return  ; 
        }
        
        for(int ind=i ; ind<=n ; ind++)
        {
            temp.push_back(ind) ; 
            solve(ind+1 , k-1 , n, ans, temp) ; 
            temp.pop_back() ; 
        }
        
        
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans ; 
        vector<int> temp ; 
        solve(1 , k , n , ans , temp) ; 
        
        return ans ; 
    }
};