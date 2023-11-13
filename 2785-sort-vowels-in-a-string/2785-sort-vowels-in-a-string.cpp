class Solution {
public:
    
    bool isVowel(char ch)
    {
        return (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='A' || ch=='E' || ch=='I' || ch=='O' ||ch=='U') ; 
    }
    
    string sortVowels(string s) {
        string ans = "" ; 
        vector<char> temp ; 
        
        for(int i=0 ; i<s.size() ; i++)
        {
            if(isVowel(s[i]))
            {
                ans += '/' ; 
                temp.push_back(s[i]) ; 
            }
            else
                ans += s[i] ; 
        }
        
        sort(temp.begin(), temp.end()) ; 
        
        int j=0 ; 
        
        for(int i=0 ; i<ans.size() ; i++)
        {
            if(ans[i] == '/')
                ans[i] = temp[j++] ; 
        }
        
        return ans ; 
    }
};