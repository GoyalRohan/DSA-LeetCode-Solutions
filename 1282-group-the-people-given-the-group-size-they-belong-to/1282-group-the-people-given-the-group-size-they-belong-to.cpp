class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ans ; 
        map<int , vector<int>> mpp ; 
        
        for(int i=0 ; i<groupSizes.size() ; i++)
        {
            mpp[groupSizes[i]].push_back(i) ; 
        }
        
        for(auto m : mpp)
        {
            int val = m.first ; 
            auto vec = m.second ; 
            int cnt = 0 ; 
            vector<int> temp ; 
            
            for(int i=0 ; i<vec.size() ; i++)
            {
                cnt++ ; 
                temp.push_back(vec[i]) ; 
                if(cnt%m.first == 0)
                {
                    ans.push_back(temp) ; 
                    temp.clear() ; 
                }
            }
        }
        
        
        return ans ; 
    }
};