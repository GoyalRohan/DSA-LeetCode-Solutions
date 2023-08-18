class Solution {
public:
    
    void display(vector<vector<bool>> &board , vector<vector<string>> &ans )
    {
        vector<string> temp ;
        for(auto row : board)
        {
            string s = "" ; 
             
            for(auto ele : row)
            {
                if(ele)
                    s.push_back('Q') ; 
                else
                    s.push_back('.') ; 
            }
            temp.push_back(s) ;  
        }
        ans.push_back(temp) ; 
    }
    
    bool isSafe(int row , int col , vector<vector<bool>> &board)
    {
        //FOR VERTICAL ROW
        for(int i=0 ; i<row ; i++)
            if(board[i][col])
                return false ; 
        
        //FOR LEFT DIAGONAL
//         int maxleft = min(row , col) ; 
//         for(int i=1 ; i<=maxleft ; i++)
//         {
//             if(board[row-i][col-i])
//                 return false ; 
//         }
        
        int i=1 ;
        while(row-i >= 0 && col-i >= 0)
        {
            // cout<<i<<endl ; 
            if(board[row-i][col-i])
                return false ; 
            i++ ;
        }
        
        //FOR RIGHT DIAGONAL
        int n = board.size() ; 
        // int maxright = min(row ,n-col-1) ; 
        // for(int i=1 ; i<=maxright ; i++)
        // {
        //     if(board[row-i][col+i])
        //         return false ; 
        // }
        
        i=1 ; 
        while(row-i>=0 && col+i < n)
        {
            if(board[row-i][col+i])
                return false ; 
            i++ ; 
        }
        
        return true ; 
    }
    
    void solve(int row , int n , vector<vector<string>> &ans , vector<vector<bool>> &board)
    {
        if(row == n)
        {
            display(board , ans) ; 
            return  ; 
        }
        
        for(int col=0 ; col<n ; col++)
        {
            if(isSafe(row , col , board))
            {
                board[row][col] = true ; 
                solve(row+1 , n , ans , board) ; 
                board[row][col] = false ; 
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans ; 
        vector<vector<bool>> board(n , vector<bool> (n , false)) ; 
        solve(0 , n , ans , board) ; 
        return ans ; 
    }
};