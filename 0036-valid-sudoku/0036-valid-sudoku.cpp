class Solution {
public:
    
    bool isSafe(int row , int col, char dig , int n , vector<vector<char>>& board)
    {
        for(int i=0 ; i<9 ; i++)
        {
            if(i!= col && board[row][i] == dig)
                return false ; 
        }
        
        for(int i=0 ; i<9 ; i++)
        {
            if(i!= row && board[i][col] == dig)
                return false ; 
        }
        
        
        int rowstart = row - row%3 ; 
        int colstart = col - col%3 ; 
        
        for(int i=rowstart ; i< rowstart+3 ; i++)
        {
            for(int j=colstart ; j<colstart+3 ; j++)
            {
                if(i!= row && j!=col && board[i][j] == dig)
                    return false ; 
            }
        }
        
        return true ; 
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size() ; 
        
        for(int i=0 ; i<n ; i++)
        {
            for(int j=0 ; j<n ; j++)
            {
                if(board[i][j] != '.')
                {
                    if(!(isSafe(i , j , board[i][j] , n, board)))
                    {
                        // cout<<i<<" "<<j<<" : "<< board[i][j] ; 
                            return false ;
                    }
                         
                }
                    
            }
        }
        
        return true ; 
        
    }
};