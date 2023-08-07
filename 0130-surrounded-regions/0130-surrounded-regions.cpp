class Solution {
public:
    
    bool onborder(int i , int j , int n , int m)
    {
        if(i==0 || j==0 || i==n-1 || j == m-1)
            return true ; 
        return false ; 
    }
    
    void dfs(int i, int j , vector<vector<char>>& board, int n, int m)
    {
        if(i<0 || j<0 || i>=n || j>=m || board[i][j] == 'a' || board[i][j] == 'X')
            return ; 
        
        board[i][j] = 'a' ; 
        dfs(i-1 , j , board, n , m) ; 
        dfs(i+1 , j , board, n , m) ; 
        dfs(i , j-1 , board, n , m) ; 
        dfs(i , j+1 , board, n , m) ; 
    }
    
    void solve(vector<vector<char>>& board) {
        int n = board.size() , m = board[0].size() ;
        for(int i=0 ; i<n  ; i++)
        {
            for(int j=0 ; j<m ; j++)
            {
                if(board[i][j] == 'O' && onborder(i , j , n , m))
                {
                    dfs(i , j , board , n , m) ; 
                }
            }
        }
        
        
        for(int i=0 ; i<n  ; i++)
        {
            for(int j=0 ; j<m ; j++)
            {
                if(board[i][j] == 'O')
                    board[i][j] = 'X' ;
                
                else if(board[i][j] == 'a')
                    board[i][j] = 'O' ;
            }
        }
        
        return ;
    }
};