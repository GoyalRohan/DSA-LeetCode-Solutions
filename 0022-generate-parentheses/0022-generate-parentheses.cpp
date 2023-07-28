class Solution {
public:
    
//     void solve(int open , int closed , string &temp , vector<string> &ans)
//     {
        
//         if(open > closed || open < 0)
//             return  ; 
        
//         if(open + closed == 0)
//         {
//             ans.push_back(temp) ; 
//             return ; 
//         }
        
//         temp += "(" ; 
//         solve(open-1 , closed , temp , ans) ; 
//         temp.pop_back() ; 
        
//             temp+= ")" ; 
//             solve(open , closed-1 , temp , ans) ; 
//             temp.pop_back() ; 

            
//     }
    
    void solve(int open , int closed , string temp , vector<string> &ans)
    {
        if(open == 0 && closed == 0)
        {
            ans.push_back(temp) ; 
            return ;
        }
        
        if(open >= 0)
            solve(open-1 , closed , temp + "(" , ans) ; 
        
        if(closed > open)
            solve(open , closed-1 , temp + ")" , ans) ; 
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans ; 
        string temp = "";
        solve(n , n, temp , ans) ;
        return ans; 
    }
};