class Solution {
public:
    bool wordPattern(string pattern, string s) {
        stringstream iss(s) ; 
        vector<string> v ; 
        string word ; 
        
        while(iss >> word)
            v.push_back(word) ; 
        
        if(pattern.size() != v.size())
            return false ; 
        
        unordered_set<string> check ; 
        unordered_map<char , string> mpp ; 
        
        
        for(int i=0 ; i<pattern.size() ; i++)
        {
            char ch = pattern[i] ; 
            
            if(mpp.find(ch) != mpp.end())
            {
                if(mpp[ch] != v[i])
                    return false ; 
            }
            else
            {
                if(check.count(v[i]) > 0)
                    return false ; 
                
                check.insert(v[i]) ; 
                mpp[ch] = v[i]  ;
            }
        }
        
        return true ; 
        
    }
};