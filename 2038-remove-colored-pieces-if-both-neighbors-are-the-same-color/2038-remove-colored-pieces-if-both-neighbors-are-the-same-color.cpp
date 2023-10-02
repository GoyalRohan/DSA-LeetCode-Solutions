class Solution {
public:
    bool winnerOfGame(string colors) {
        int n = colors.size() ; 
        int scoreA = 0 , scoreB = 0 ; 
        
        for(int i=0 ; i<n ; i++)
        {
            char ch = colors[i] ; 
            int cnt= 1 ; 
            int ind=i+1 ; 
            
            while(ind<n && colors[ind] == colors[i])
            {
                cnt++ ; ind++ ; 
            }
            
            if(ch == 'A')
                scoreA += cnt-2 > 0 ? cnt -2 : 0 ; 
            else if(ch == 'B')
                scoreB += cnt-2 > 0 ? cnt -2 : 0 ; 
            
            i = ind-1 ; 
            
        }
        
        return scoreA > scoreB ; 
    }
};