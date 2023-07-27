class Solution {
public:
    bool isSafe(int i , int j, int m , int n)
    {
        if(i<0 || j<0 || i>=m || j>=n)
            return false ; 
        return true ; 
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size() , n  = board[0].size() ; 
        
        int dx[]= {1 , 1 , 0 , -1 , -1 , -1 , 0 , 1} ;
        int dy[]= {0 , 1 , 1 , 1 , 0 ,-1 ,  -1 , -1} ;
        
        for(int i=0 ; i<m ; i++)
        {
            for(int j=0 ; j<n ; j++)
            {
                int liveCounts = 0 ; 
                for(int k=0 ; k<8 ; k++)
                {
                    if(isSafe(i+dx[k] , j+dy[k] , m , n) && abs(board[i+dx[k]][j+dy[k]]) == 1)
                        liveCounts++ ; 
                }
                
                if(board[i][j] == 1 && (liveCounts < 2 || liveCounts >3))
                    board[i][j] = -1 ; 
                    
                if(board[i][j] == 0 && liveCounts == 3)
                    board[i][j] = 2 ; 
            }
        }
        
        for(int i=0 ; i<m ; i++)
        {
            for(int j=0 ; j<n ; j++)
            {
                board[i][j] = board[i][j] > 0 ?1 : 0 ; 
            }
        }
        
        
       return ;  
    }
};