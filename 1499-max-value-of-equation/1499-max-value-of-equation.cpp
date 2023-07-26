class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int n = points.size() ; 
        priority_queue<pair<int, int>> pq ; 
        int maxi = INT_MIN ; 
        
        for(int i=0 ; i<n ; i++)
        {
            int sum = points[i][0] + points[i][1] ; 
            while(!pq.empty() && points[i][0] - pq.top().second > k)
                pq.pop() ; 
            
            if(!pq.empty())
            {
                maxi = max(maxi, sum + pq.top().first) ; 
            }
            
            pq.push({points[i][1] - points[i][0] , points[i][0]}) ; 
        }
        
        return maxi ; 
        
    }
};