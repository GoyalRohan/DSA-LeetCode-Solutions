class Solution {
public:
    vector<vector<string>> ans ;
    
    bool isPalindrome(int j, int i , string &s)
    {
        while(i < j)
        {
            if(s[i] != s[j])
                return false ; 
            i++ ; j-- ; 
        }
        return true ; 
    }
    
    void solve(int ind, string s , vector<string> &output)
    {
        if(ind == s.size())
        {
            ans.push_back(output) ; 
            return ; 
        } 
        
        for(int i=ind ; i<s.size() ; i++)
        {
            if(isPalindrome(i, ind , s))
            {
                // cout<<ind<<" "<<i<<":" << s.substr(ind, i+1-ind)<<endl ; 
                output.push_back(s.substr(ind, i+1-ind)) ; 
                solve(i+1 , s , output) ; 
                output.pop_back() ; 
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
         
        vector<string> output ; 
        solve(0 , s , output) ; 
        return ans ; 
    }
};