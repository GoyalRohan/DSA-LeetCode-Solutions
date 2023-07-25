class Solution {
public:
    
    bool solve(int i , int j, vector<vector<char>>& board, string word)
    {
        if(word.size() == 0)
            return true ; 
        
        if(i<0 || j<0 || i>= board.size() || j >= board[0].size())
            return false ; 
        
        if(board[i][j] != word[0] || board[i][j] == '0')
            return false ; 
        
        char temp = board[i][j] ; 
        board[i][j] = '0' ; 
        
        bool up = solve(i-1 , j , board , word.substr(1)) ; 
        bool down = solve(i+1 , j , board , word.substr(1)) ; 
        bool left = solve(i , j-1 , board , word.substr(1)) ; 
        bool right = solve(i , j+1 , board , word.substr(1)) ; 
        
        board[i][j] = temp ; 
        
        if(up || down || left || right)
            return true ; 
        
        return false ; 
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size() , m = board[0].size() ; 
        queue<pair<int, int>> q ; 
        
        for(int i=0 ; i<n ; i++)
        {
            for(int j=0 ; j<m ; j++)
            {
                if(board[i][j] == word[0])
                {
                    q.push({i , j}) ; 
                }
            }
        }
        
        while(!q.empty())
        {
            int i = q.front().first , j = q.front().second ; 
            q.pop() ; 
            
            if(solve(i , j, board, word))
                return true ; 
        }
        
        return false ; 
        
    }
};