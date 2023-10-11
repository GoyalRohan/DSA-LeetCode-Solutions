class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int, int >> dq ; 
        vector<int> ans ; 
        
        for(int i=0 ; i<nums.size() ; i++)
        {
            if(!dq.empty() && i-k+1 > dq.front().second)
                dq.pop_front() ; 
            
            while(!dq.empty() && nums[i] > dq.back().first)
                dq.pop_back() ; 
            
            dq.push_back({nums[i] , i}) ; 
            
            if(i >= k-1)
                ans.push_back(dq.front().first) ; 
        }
        
        return ans ; 
    }
};