class Solution {
public:
    
    void dfs(int node , set<int> &v , map<int , vector<int>> &mpp , vector<int> &ans)
    {
        if(v.find(node) != v.end())
            return ; 
        
        v.insert(node) ; 
        ans.push_back(node) ; 
        
        for(auto x : mpp[node])
            dfs(x , v , mpp , ans) ; 
    }
    
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        int n = adjacentPairs.size() ; 
        map<int , vector<int>> mpp ; 
        
        for(auto a : adjacentPairs)
        {
            mpp[a[0]].push_back(a[1]) ; 
            mpp[a[1]].push_back(a[0]) ; 
        }
        
        int terminal = 0 ; 
        for(auto m : mpp)
        {
            if(m.second.size() == 1)
            {
                terminal = m.first ; 
                break ; 
            }
        }
        
        set<int> v ; 
        vector<int> ans ; 
        dfs(terminal , v , mpp , ans) ; 
        return ans ; 
    }
};