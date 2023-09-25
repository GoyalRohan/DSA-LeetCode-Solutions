class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> hash(26 , 0) ; 
        char ans = 'a'; 
        
        for(auto ele : s)
        {
            hash[ele - 'a']++ ; 
        }
        
        for(auto ele : t)
        {
            hash[ele - 'a']-- ; 
        }
        
        for(int i=0 ; i<26 ; i++)
        {
            if(hash[i] == -1)
            {
                ans = 'a' + i ; 
                break ; 
            }
        }
        
        return ans ; 
    }
};