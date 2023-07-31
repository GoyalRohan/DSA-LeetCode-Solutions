class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size() ; 
        vector<int> ans ; 
        // priority_queue<pair<int, int> , vector<pair<int , int>> , greater<pair<int, int>>> pq ;
        // priority_queue<pair<int, int>> pq ; 
        deque<pair<int, int>> dq ; 
        
        
        for(int i=0 ; i<n ; i++)
        {
            
            if(!dq.empty() && i-k+1 > dq.front().second)
                dq.pop_front() ; 
             
            while(!dq.empty() && dq.back().first < nums[i])
            {
                dq.pop_back() ; 
            }
            
            dq.push_back({nums[i] , i}) ; 
            
            if(i >= k-1)
                ans.push_back(dq.front().first) ; 
        }
        
        return ans ;
            
    }
};