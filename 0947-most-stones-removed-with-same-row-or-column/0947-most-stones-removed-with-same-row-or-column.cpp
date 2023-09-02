class Solution {
public:
    
    void dfs(int index , vector<int> &vis, vector<vector<int>>& stones)
    {
        vis[index] = true ; 
        
        for(int i=0 ; i<stones.size() ; i++)
        {
            if(vis[i] == 0 && (stones[index][0] == stones[i][0] || stones[index][1] == stones[i][1] ))
                dfs(i , vis , stones) ; 
        }
        
    }
    
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size() ; 
        vector<int> vis(n , 0) ; 
        int res = 0 ; 
        
        for(int i=0 ; i<n ; i++)
        {
            if(vis[i] == 0)
            {
                dfs(i , vis , stones) ; 
                res++ ; 
            }
        }
        
        return n - res ; 
    }
};