class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size()  ; 
        
        reverse(board.begin() , board.end()) ; 
        for(int i=1 ; i<n ; i++)
        {
            if(i%2 == 1)
                reverse(board[i].begin() , board[i].end()) ; 
        }
        
        int ans = 0 ; 
        queue<int> q ; 
        q.push(0) ; 
        int end = n*n - 1 ; 
        vector<vector<bool>> vis(n , vector<bool>(n , false )) ;
        vis[0][0] = true ; 
        
        while(!q.empty())
        {
            int size = q.size() ; 
            ans++ ; 
            while(size-- > 0)
            {
                int start = q.front() ; 
                q.pop() ; 
                for(int i=1 ; i<=6 ; i++)
                {
                    int temp = start + i ; 
                    int r = temp/n , c = temp%n ; 
                    
                    if(board[r][c] != -1)
                    {
                        temp = board[r][c] - 1 ; 
                        r = temp/n ; c = temp%n ; 
                    }
                    
                    if(temp > end || vis[r][c] == true)
                        continue ; 
                    
                    if(temp == end)
                        return ans ; 
                    
                    q.push(temp) ; 
                    vis[r][c] = true ; 
                }
            }
        }
        
        return -1 ; 
    }
};