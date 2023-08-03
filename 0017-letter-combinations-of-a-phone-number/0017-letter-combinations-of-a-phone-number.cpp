class Solution {
public:
    
    string mapping[10] = {"", "", "abc", "def", "ghi", "jkl","mno","pqrs","tuv","wxyz"};
    
    void solve(int ind, string temp , string digits, vector<string> &ans)
    {
            if(ind >= digits.size())
            {
                ans.push_back(temp) ; 
                return ; 
            }
        
            string str = mapping[digits[ind]-'0'] ; 
            
            for(int i=0 ; i<str.size() ; i++)
            {
                temp += str[i] ; 
                solve(ind+1 , temp , digits , ans) ; 
                temp.pop_back() ; 
            }
        
    }
    
    
    vector<string> letterCombinations(string digits) {
        vector<string> ans ; 
        if(digits.size() == 0)
            return ans ; 
        
        string temp = "" ; 
        solve(0 , temp , digits, ans) ; 
        return ans ; 
        
    }
};