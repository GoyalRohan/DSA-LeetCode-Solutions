class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ans ; 
        map<int , vector<int>> mpp ; 
        
        for(int i=0 ; i<groupSizes.size() ; i++)
        {
            int key = groupSizes[i] ; 
            mpp[key].push_back(i) ; 
            
            if(mpp[key].size() == key)
            {
                ans.push_back(mpp[key]) ; 
                mpp[key].clear() ; 
            }
        }
        
        
        
        return ans ; 
    }
};