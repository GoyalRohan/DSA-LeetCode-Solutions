class Solution {
public:
    
    string mapping[10] = {"", "", "abc", "def", "ghi", "jkl","mno","pqrs","tuv","wxyz"};
    
    void solve(int index , string ans , string digits , vector<string> &final)
    {
        if(index == digits.size())
        {
            final.push_back(ans) ; 
            return ;
        }
        
        
        string word = mapping[digits[index] - '0'] ;
        
        for(int i=0 ; i<word.size() ; i++)
        {
            ans.push_back(word[i]) ; 
            solve(index+1 , ans , digits , final) ; 
            ans.pop_back() ; 
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> final ; 
        
        if(digits.size() == 0)
            return final ; 
        
        
        string ans = "" ; 
        solve(0 , ans , digits , final) ;
        
        return final ;
    }
};