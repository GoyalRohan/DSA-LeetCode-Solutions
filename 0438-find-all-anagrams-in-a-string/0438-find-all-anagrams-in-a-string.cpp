class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> tmap , dmap ; 
        int k = p.size() , n = s.size() ; 
        vector<int> ans ; 
        
        for(auto ele : p)
            dmap[ele]++ ; 
        
        int i=0 , j=0; 
        for(i=0 ; i<k-1 ; i++)
            tmap[s[i]]++ ; 
        
        for(i=k-1 ; i<n ; i++)
        {
            tmap[s[i]]++ ; 
            if(tmap == dmap)
                ans.push_back(j) ; 
            
            tmap[s[j]]-- ; 
            if(tmap[s[j]] == 0)
                tmap.erase(s[j]) ; 
            
            j++ ; 
        }
        
        return ans ; 
        
    }
};