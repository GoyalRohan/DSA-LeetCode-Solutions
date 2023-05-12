class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mpp1, mpp2 ; 
        
        for(auto a : s)
            mpp1[a]++ ; 
        
        for(auto a : t)
            mpp2[a]++ ; 
        
        return  mpp1 == mpp2 ; 
    }
};