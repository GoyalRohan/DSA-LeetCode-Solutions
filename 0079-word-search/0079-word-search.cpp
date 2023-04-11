class Solution {
public:
    
    bool solve(int i, int j, int x,  string &word, vector<vector<char>>& board)
    {
        if(x == word.size())
            return true ; 
        
        if(i >= board.size() || j >= board[0].size())
            return false ; 
        
        if(board[i][j] == '0' || board[i][j] != word[x])
            return false ; 
        
        char temp = board[i][j] ; 
        board[i][j] = '0' ; 
        bool up = solve(i+1 , j , x+1 , word , board) ; 
        bool down = solve(i-1 , j , x+1 , word , board) ;
        bool left = solve(i , j-1 , x+1 , word , board) ;
        bool right = solve(i , j+1 , x+1 , word , board) ;
        
        board[i][j] = temp ; 
        
        return (up || down || left || right) ; 
        
    }
    
    bool exist(vector<vector<char>>& board, string word) { 
        
        for(int i=0 ; i<board.size() ; i++)
        {
            for(int j=0 ; j<board[0].size() ; j++)
            {
                if(board[i][j] == word[0])
                {
                    if(solve(i , j , 0 , word , board))
                        return true ;
                }
                   
            }
        }
        
         
        
        return false ; 
    }
};