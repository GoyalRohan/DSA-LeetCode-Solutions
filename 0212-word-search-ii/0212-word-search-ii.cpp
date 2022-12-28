class Solution {
public:
    
    struct node 
    {
        char c ; 
        node *child[26] ; 
        int ends  ; 
        string word ; 
    };
    
    node *getnode(char ch)
    {
        node *newnode = new node ; 
        newnode->c = ch ; 
        for(int i=0; i<26 ; i++)
            newnode->child[i] = NULL ; 
        
        newnode->ends = 0 ; 
        newnode->word = "" ; 
        
        return newnode ; 
    }
    
    node *root = getnode('/') ; 
    
    void insert(string s)
    {
        node *cur = root ; 
        int i=0 ;
        while(s[i])
        {
            int index = s[i] - 'a' ; 
            if(cur->child[index] == NULL)
            {
                cur->child[index] = getnode(s[i]) ; 
            }

            cur = cur->child[index] ; 
            i++ ;
        }
        
        cur->ends = 1 ; 
        cur->word = s ; 
    }
    
    void solve(int i, int j, int r, int c ,vector<string> &ans ,vector<vector<char>>& board, vector<string>& words , node *cur )
    {
        int index = board[i][j] - 'a' ; 
        if(board[i][j] == '$' || cur->child[index] == NULL)
            return ; 
        
        cur = cur->child[index] ; 
        
        if(cur->ends > 0)
        {
            ans.push_back(cur->word) ; 
            cur->ends -= 1 ; 
        }
        
        char ch = board[i][j] ; 
        board[i][j] = '$' ; 
        
        if(i > 0)
            solve(i-1 , j , r , c , ans, board , words , cur) ; 
        if(i < r-1)
            solve(i+1 , j , r , c , ans, board , words , cur) ; 
        if(j > 0)
            solve(i , j-1 , r , c , ans, board , words , cur) ; 
        if(j < c-1)
            solve(i , j+1 , r , c , ans, board , words , cur) ; 
        
        board[i][j] = ch ; 
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for(auto word : words)
            insert(word) ; 
        
        int r = board.size() ; 
        int c = board[0].size() ; 
        
        vector<string> ans ; 
        
        for(int i=0 ; i<r ; i++)
        {
            for(int j=0 ; j<c ; j++)
            {
                solve(i , j , r , c , ans , board , words , root) ; 
            }
        }
        
        return ans ; 
    }   
};