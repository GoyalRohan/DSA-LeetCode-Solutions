class Solution {
public:
    int longestValidParentheses(string s) {
        int maxi = 0 ; 
        stack<int> ind ; 
        stack<int> ch ; 
        
        ind.push(-1)  ;
        
        for(int i=0 ; i<s.size() ; i++)
        {
            if(s[i] == '(')
            {
                ind.push(i) ;
                ch.push('(') ; 
            }
                
            else
            {
                if(!ch.empty() && ch.top() == '(')
                {
                    ind.pop() ;
                    ch.pop() ; 
                    maxi = max(maxi, i - ind.top()) ; 
                }
                else
                    ind.push(i) ; 
            }
        }
        
        return maxi ; 
    }
};