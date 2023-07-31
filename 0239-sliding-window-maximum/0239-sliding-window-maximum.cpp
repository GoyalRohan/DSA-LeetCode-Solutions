class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size() ; 
        vector<int> ans ; 
        // priority_queue<pair<int, int> , vector<pair<int , int>> , greater<pair<int, int>>> pq ;
        priority_queue<pair<int, int>> pq ; 
        
        for(int i=0 ; i<k-1 ; i++)
        {
            pq.push({nums[i] , i}) ; 
        }
        
        for(int i=k-1 ; i<n ; i++)
        {
            pq.push({nums[i] , i}) ; 
            while(!pq.empty() && pq.top().second < i-k+1)
            {
                pq.pop() ; 
            }
            
            if(!pq.empty())
            {
                ans.push_back(pq.top().first) ; 
            }
        }
        
        return ans ;
            
    }
};