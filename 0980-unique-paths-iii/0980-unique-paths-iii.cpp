class Solution {
public:
    
    int solve(int row , int col , int m , int n , vector<vector<int>>& grid , int zero)
    {
        
        if(grid[row][col]==3 || grid[row][col] == -1)
            return 0 ; 
        
        if(grid[row][col] == 2)
            return zero == -1 ?1 : 0 ; 
        
        
        int temp = grid[row][col] ; 
        grid[row][col] = 3 ; 
        zero -- ; 
        
        int right=0 , left=0 , up=0 , down=0; 
        
        if(row-1 >=0)
            up = solve(row-1 , col , m , n , grid ,zero ) ;
        if(row + 1 <m)
            down = solve(row+1 , col , m , n , grid ,zero) ; 
        if(col-1 >= 0)
            left = solve(row , col-1 , m , n , grid ,zero ) ; 
        if(col + 1 <n)
            right = solve(row , col+1 , m , n , grid ,zero ) ; 
        
        grid[row][col] = temp ; 
        zero ++ ;
        return up + down + left + right ;  
        
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size() ; 
        int n = grid[0].size() ; 
        int row =-1 , col = -1 ; 
        int zero = 0 ; 
        
        for(int i=0 ; i<m ; i++)
        {
            for(int j=0 ; j<n ; j++)
            {
                if(grid[i][j] == 1)
                {
                    row = i ; col = j ; 
                    
                }
                else if(grid[i][j] == 0)
                    zero++ ; 
            }
        }
        
        
        int count = solve(row , col , m , n , grid , zero ) ; 
        return count ; 
    }
};