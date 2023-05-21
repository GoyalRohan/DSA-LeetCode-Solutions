class Solution {
public:
    queue<pair<int, int>> q ; 
    
    void dfs(int i, int j , vector<vector<int>>& grid)
    {
        int n = grid.size() ; 
        if(i<0 || i>=n || j<0 || j>=n || grid[i][j] == 0 || grid[i][j] == 2)
            return ; 
        
        q.push({i , j}) ; 
        grid[i][j] = 2 ; 
        
        dfs(i-1 , j , grid) ; 
        dfs(i+1 , j , grid) ; 
        dfs(i , j-1 , grid) ; 
        dfs(i , j+1 , grid) ; 
        
    }
    
    
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size() ; 
        bool flag = false ; 
        
        for(int i=0 ; i<n ; i++)
        {
            for(int j=0 ; j<n ; j++)
            {
                if(grid[i][j] == 1)
                {
                    dfs(i , j , grid) ; 
                    flag = true ; 
                    break ; 
                }
            }
            if(flag == true)
                break ; 
        }
        
        int ans = 0 ; 
        bool flag2 = false ; 
        while(!q.empty())
        {
            int size = q.size() ; 
            while(size-- > 0)
            {
                auto node = q.front() ;
                int x = node.first , y = node.second ; 
                q.pop() ; 
                
                vector<vector<int>> d = {{1,0}, {0,1}, {-1,0}, {0,-1}};

                // vector<vector<int>> d = {{-1 , 0} , {1 , 0} , {0 , -1} , {0 , 1}} ; 
                
                for(int i=0 ; i<4 ; i++)
                {
                    int dx = x + d[i][0] , dy = y + d[i][1] ; 
                    
                    if(dx>=0 && dx<n && dy>=0 && dy<n && grid[dx][dy] == 1)
                    {
                        return ans ; 
                    }
                    
                    if(dx>=0 && dx<n && dy>=0 && dy<n && grid[dx][dy] == 0)
                    {
                        q.push({dx , dy}) ; 
                        grid[dx][dy] = 2 ; 
                    }
                }
            }
            ans++ ; 
        }
        
        return -1 ;
    }
};