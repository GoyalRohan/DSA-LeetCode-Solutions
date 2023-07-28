class Solution {
public:
    
    void solve(int open , int closed , string temp , vector<string> &ans)
    {
        
        if(open == 0)
        {
            while(closed > 0)
            {
                temp += ")" ; 
                closed-- ; 
            }
            
            ans.push_back(temp) ; 
            return ; 
        }
        
        // temp += "(" ; 
        solve(open-1 , closed , temp + "(" , ans) ; 
        // temp.pop_back() ; 
        
        if(open < closed)
        {
            // temp+= ")" ; 
            solve(open , closed-1 , temp + ")", ans) ; 
            // temp.pop_back() ; 
        }
            
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans ; 
        string temp = "";
        solve(n , n, temp , ans) ;
        return ans; 
    }
};