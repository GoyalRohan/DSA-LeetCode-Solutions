class Solution {
public:
    string reverseWords(string s) {
        vector<string> store ; 
        
        string temp = ""; 
        
        for(int i=0 ; i<s.size() ; i++)
        {
            if(s[i] == ' ')
            {
                if(temp.size() > 0)
                {
                    store.push_back(temp) ; 
                    temp = "" ;
                }
                
            }
            else
                temp += s[i] ; 
        }
        
        if(temp.size() > 0)
            store.push_back(temp) ; 
        
        string ans = "" ; 
        for(int i=store.size() -1 ; i>=0 ; i--)
        {
            ans += store[i] ; 
            if(i != 0)
                ans += ' '; 
        }
        
        return ans ; 
    }
};