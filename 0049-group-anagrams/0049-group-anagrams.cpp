class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans ; 
        unordered_map<string, vector<string>> mpp ; 
        
        for(auto word : strs)
        {
            string temp = word ; 
            sort(temp.begin(), temp.end()) ; 
            mpp[temp].push_back(word) ; 
        }
        
        for(auto m : mpp)
            ans.push_back(m.second) ; 
        
        return ans ; 
    }
};