class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp ; 
        for(auto n : nums)
            mpp[n]++ ;
        
        priority_queue<pair<int, int>> pq ; 
        for(auto m : mpp)
        {
            pq.push({m.second , m.first}) ; 
        }
        
        vector<int> ans; 
        while(!pq.empty() && k > 0)
        {
            ans.push_back(pq.top().second) ; 
            pq.pop() ; 
            k-- ; 
        }
        
        return ans ; 
    }
};