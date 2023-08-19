class Solution {
public:
    
    bool isSafe(int row , int col, char dig , int n , vector<vector<char>>& board)
    {
        for(int i=0 ; i<9 ; i++)
        {
            if(board[i][col] == dig || board[row][i] == dig)
                return false ; 
        }
        
        int rowstart = row - row%3 ; 
        int colstart = col - col%3 ; 
        
        for(int i=rowstart ; i< rowstart+3 ; i++)
        {
            for(int j=colstart ; j<colstart+3 ; j++)
            {
                if(board[i][j] == dig)
                    return false ; 
            }
        }
        
        return true ; 
    }
    
    bool solve(vector<vector<char>>& board, int n)
    {
     
        int row = -1 , col = -1 ; 
        bool emptyleft = false ;
        
        for(int i=0 ; i<n ; i++)
        {
            for(int j=0 ; j<n ; j++)
            {
                if(board[i][j] == '.')
                {
                    emptyleft = true ;
                    row = i ; col = j ; 
                    break ; 
                }
                    ; 
            }
            if(emptyleft == true)
                break ; 
        }
        
        if(emptyleft == false)
            return true ; 
        
        
        for(char dig='1' ; dig<='9' ; dig++)
        {
            if(isSafe(row , col , dig , n , board))
            {
                board[row][col] = dig ; 
                if(solve(board , n))
                    return true ; 
                board[row][col] = '.' ; 
                
            }
        }
        
        return false ; 
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        int n = board.size() ; 
        
        if(solve(board , n))
            return ; 
        
        return  ; 
    }
};