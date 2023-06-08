class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        
        int ans = 0 ; 
        int m = grid[0].size() ; 
        
        for (auto row : grid)
        {
            ans += upper_bound(row.rbegin() , row.rend() , -1) - row.rbegin() ; 
        }
        
        return ans ; 
    }
};